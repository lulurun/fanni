//
// server.cpp
// ~~~~~~~~~~
//
// Copyright (c) 2003-2008 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <ctime>
#include <iostream>
#include <string>
#include <boost/array.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>

using namespace std;
using boost::asio::ip::tcp;
using boost::asio::ip::udp;

std::string make_daytime_string() {
	using namespace std;
	// For time_t, time and ctime;
	time_t now = time(0);
	return ctime(&now);
}

class udp_server {
public:
	udp_server(boost::asio::io_service& io_service) :
		socket_(io_service, udp::endpoint(udp::v4(), 9001)) {
		cout << "udp_server enter" << endl;
		start_receive();
		cout << "udp_server exit" << endl;
	}

private:
	void start_receive() {
		cout << "start receive enter" << endl;
		socket_.async_receive_from(boost::asio::buffer(recv_buffer_),
				remote_endpoint_, boost::bind(&udp_server::handle_receive,
						this, boost::asio::placeholders::error,
						boost::asio::placeholders::bytes_transferred));
		cout << "start receive exit" << endl;
	}

	void handle_receive(const boost::system::error_code& error,
			size_t bytes_recvd) {
		cout << "handle_receive enter" << endl;
		if (!error || error == boost::asio::error::message_size) {
			/*
			 boost::shared_ptr<std::string> message(new std::string(
			 make_daytime_string()));

			 socket_.async_send_to(boost::asio::buffer(*message),
			 remote_endpoint_, boost::bind(&udp_server::handle_send,
			 this, message));
			 */
			::printf("(%08x) recv size: %d\n", (unsigned int) pthread_self(),
					bytes_recvd);
			for (int i = 0; i < bytes_recvd; i++) {
				::printf("%02x ", (unsigned char) this->recv_buffer_[i]);
			}
			cout << endl;
			start_receive();
		}
		cout << "handle_receive exit" << endl;
	}

	void handle_send(boost::shared_ptr<std::string> /*message*/) {
	}

	udp::socket socket_;
	udp::endpoint remote_endpoint_;
	boost::array<char, 1500> recv_buffer_;
};

int main() {
	try {
		boost::asio::io_service io_service;
		udp_server server2(io_service);
		io_service.run();
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}

