{
	FileInfo Low 154 NotTrusted Unencoded
	{
		FileInfo		Single
		{	TransferID		LLUUID	}
		{	Size			S32	}
		{	Name			Variable	2	}
	}
}

{
	FileData High 17 NotTrusted Unencoded
	{
		FileData Single
		{	TransferID	LLUUID	}
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
	UseCircuitCode Low 3 NotTrusted Unencoded
	{
		CircuitCode		Single
		{	Code		U32		}
		{	SessionID	LLUUID	}
		{	ID			LLUUID	} // agent id
	}
}

{
	CloseCircuit Fixed 0xFFFFFFFD NotTrusted Unencoded
}


