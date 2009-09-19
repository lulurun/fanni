{
	FileInfo Low 154 NotTrusted Unencoded
	{
		FileInfo		Single
		{	SenderTransferID	LLUUID			}
		{	Size				S32				}
		{	Name				Variable	2	}
	}
}

{
	FileInfoReply Low 155 NotTrusted Unencoded
	{
		FileInfo		Single
		{	ReceiverTransferID	LLUUID	}
		{	SenderTransferID	LLUUID	}
	}
}

{
	TransferComplete Low 156 NotTrusted Unencoded
	{
		FileData Single
		{	SenderTransferID	LLUUID	}
	}
}

{
	FileData High 17 NotTrusted Unencoded
	{
		FileData Single
		{	ReceiverTransferID	LLUUID	}
		{	DataNumber	S32	}
		{	Data		Variable 2	}
	}
}

// system packets
{
        PacketAck Fixed 0xFFFFFFFB NotTrusted Unencoded
        {
                Packets                 Variable                
                {       ID                      U32     }
        }
}

{
	OpenConnection Low 3 NotTrusted Unencoded
	{
		OpenConnection		Single
		{	Code		U32		}
	}
}

{
	OpenConnectionReply Low 4 NotTrusted Unencoded
	{
		OpenConnectionReply		Single
		{	Code		U32		}
	}
}

{
	CloseConnection Low 5 NotTrusted Unencoded
}

{
	CloseConnectionReply Low 6 NotTrusted Unencoded
}
