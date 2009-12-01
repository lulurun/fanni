{
	FileInfo Low 513 NotTrusted Unencoded
	{
		FileInfo		Single
		{	SenderTransferID	LLUUID			}
		{	Size				S32				}
		{	Name				Variable	2	}
	}
}

{
	FileInfoReply Low 514 NotTrusted Unencoded
	{
		FileInfo		Single
		{	ReceiverTransferID	LLUUID	}
		{	SenderTransferID	LLUUID	}
	}
}

{
	TransferComplete Low 515 NotTrusted Unencoded
	{
		FileData Single
		{	SenderTransferID	LLUUID	}
	}
}

{
	FileData High 33 NotTrusted Unencoded
	{
		FileData Single
		{	ReceiverTransferID	LLUUID	}
		{	DataNumber	S32	}
		{	Data		Variable 2	}
	}
}

// system packets
{
	OpenConnection Low 516 NotTrusted Unencoded
	{
		OpenConnection		Single
		{	Code		U32		}
	}
}

{
	OpenConnectionReply Low 517 NotTrusted Unencoded
	{
		OpenConnectionReply		Single
		{	Code		U32		}
	}
}

{
	CloseConnection Low 518 NotTrusted Unencoded
}

{
	CloseConnectionReply Low 519 NotTrusted Unencoded
}
