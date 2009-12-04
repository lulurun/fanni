/*
 * FileTransferNode.cpp
 *
 *  Created on: Aug 26, 2009
 *      Author: lulu
 */

#include <cassert>
#include <fstream>
#include "Poco/Delegate.h"
#include "fanni/FTPackets/FTPackets.h"
#include "TransferNode.h"
#include "Connection.h"
#include "SystemHandler.h"
#include "ConnectionHandler.h"

using namespace std;
using namespace Fanni;
using namespace Fanni::FileTransfer;

TransferNode::TransferNode(const EndPoint &server_ep) : LLUDPBase(server_ep) {
	FTPackets::init(this->packet_factory);

	this->system_handler_factory.registerHandler(OpenConnection_ID, new OpenConnectionPacketHandler());
	this->system_handler_factory.registerHandler(OpenConnectionReply_ID, new OpenConnectionReplyPacketHandler());

	// C -> S
	this->connection_handler_factory.registerHandler(FileInfo_ID, new FileInfoPacketHandler());
	this->connection_handler_factory.registerHandler(FileData_ID, new FileDataPacketHandler());
	this->connection_handler_factory.registerHandler(CloseConnection_ID, new CloseConnectionPacketHandler());
	// S -> C
	this->connection_handler_factory.registerHandler(FileInfoReply_ID, new FileInfoReplyPacketHandler());
	this->connection_handler_factory.registerHandler(TransferComplete_ID, new TransferCompletePacketHandler());
	this->connection_handler_factory.registerHandler(CloseConnectionReply_ID, new CloseConnectionReplyPacketHandler());

	this->ConnectionAdded += Poco::Delegate<TransferNode, const EndPoint>(this, &TransferNode::onConnectionAdded);
	this->ConnectionRemoved += Poco::Delegate<TransferNode, const EndPoint>(this, &TransferNode::onConnectionRemoved);
}

TransferNode::~TransferNode() {}

void TransferNode::onConnectionAdded(const void* pSender, const EndPoint &ep) {
	INFO_LOG("added new connection from: " << ep.toString());
}

void TransferNode::onConnectionRemoved(const void* pSender, const EndPoint &ep) {
	INFO_LOG("removed connection from: " << ep.toString());
}

void TransferNode::onConnected(const void* pSender, const EndPoint &ep) {
	INFO_LOG("connected to: " << ep.toString());
	this->connected.set();
}

void TransferNode::onDisconnected(const void* pSender, const EndPoint &ep) {
	INFO_LOG("disconnected from: " << ep.toString());
	this->disconnected.set();
}

ConnectionBasePtr TransferNode::createConnection(const PacketBasePtr &packet_base, const EndPoint &ep) {
	PacketHeader::PACKET_ID_TYPE packet_id = packet_base->header.getPacketID();
	if (packet_id == OpenConnection_ID) {
		INFO_LOG("Server: new connection from: " << ep.toString());
		Poco::SharedPtr<OpenConnectionPacket> packet = packet_base.cast<OpenConnectionPacket>();
		assert(packet.get());
		ConnectionBasePtr pConn(new ServerConnection(packet->OpenConnection.Code, ep, *this->packet_serializer, *this));
		return pConn;
	} else if (packet_id == OpenConnectionReply_ID) {
		INFO_LOG("Client: new connection to: " << ep.toString());
		Poco::SharedPtr<OpenConnectionReplyPacket> packet = packet_base.cast<OpenConnectionReplyPacket>();
		ConnectionBasePtr pConn(new ClientConnection(packet->OpenConnectionReply.Code, ep, *this->packet_serializer, *this));
		return pConn;
	} else {
		throw Poco::ApplicationException("unexpected packet type: ", packet_base->header.getPacketID()); // TODO @@@ ???
	}
}

ClientConnection &TransferNode::connect(const EndPoint &ep) {
	// switch to client mode
	this->ConnectionAdded -= Poco::Delegate<TransferNode, const EndPoint>(this, &TransferNode::onConnectionAdded);
	this->ConnectionAdded += Poco::Delegate<TransferNode, const EndPoint>(this, &TransferNode::onConnected);
	this->ConnectionRemoved -= Poco::Delegate<TransferNode, const EndPoint>(this, &TransferNode::onConnectionRemoved);
	this->ConnectionRemoved += Poco::Delegate<TransferNode, const EndPoint>(this, &TransferNode::onDisconnected);
	// Connect
	int circuit_code = 1; // TODO @@@ should be a random number
	OpenConnectionPacket *packet = new OpenConnectionPacket();
	packet->OpenConnection.Code = circuit_code;
	PacketBasePtr pPacket(packet);
	PacketBuffer buffer = this->packet_serializer->serialize(pPacket);
	this->sendData(buffer, ep);
	if (this->connected.tryWait(5000)) {
		ConnectionBasePtr &pConnBase = this->getConnection(ep);
		ClientConnection *cConn = dynamic_cast<ClientConnection*>(pConnBase.get());
		assert(cConn);
		return *cConn;
	} else {
		throw Poco::TimeoutException("connection timeout");
	}
}

bool TransferNode::disconnect(const ClientConnection &cConn) {
	// switch to client mode
	CloseConnectionPacket *packet = new CloseConnectionPacket();
	PacketBasePtr pPacket(packet);
	PacketBuffer buffer = this->packet_serializer->serialize(pPacket);
	this->sendData(buffer, cConn.getEndPoint());
	if (this->disconnected.tryWait(5000)) {
		return true;
	} else {
		return false;
	}
}

void TransferNode::sendFile(const string &file_path, const EndPoint &ep) {
	this->send_file_path = file_path;

}

