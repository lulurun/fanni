class TestMessagePacket : public PacketBase {
public:

class TestBlock1Block : public Serializable {
public:


    // TestBlock1Block Memeber List
    SerializableU32 Test1;


public:
    TestBlock1Block { };
    virtual ~TestBlock1Block() { };

protected:
    virtual void serialize(SerializableBuffer &buffer) const {
        Test1.serialize(buffer);

    }
    virtual void deserialize(SerializableBuffer &buffer) {
        Test1.deserialize(buffer);

    }
};


class NeighborBlockBlock : public Serializable {
public:


    // NeighborBlockBlock Memeber List
    SerializableU32 Test0;
    SerializableU32 Test1;
    SerializableU32 Test2;


public:
    NeighborBlockBlock { };
    virtual ~NeighborBlockBlock() { };

protected:
    virtual void serialize(SerializableBuffer &buffer) const {
        Test0.serialize(buffer);
        Test1.serialize(buffer);
        Test2.serialize(buffer);

    }
    virtual void deserialize(SerializableBuffer &buffer) {
        Test0.deserialize(buffer);
        Test1.deserialize(buffer);
        Test2.deserialize(buffer);

    }
};



    // TestMessagePacket Memeber List
    TestBlock1Block TestBlock1;
    NeighborBlockBlock NeighborBlock;


public:
    TestMessagePacket { };
    virtual ~TestMessagePacket() { };

protected:
    virtual void serialize(SerializableBuffer &buffer) const {
        TestBlock1.serialize(buffer);
        NeighborBlock.serialize(buffer);

    }
    virtual void deserialize(SerializableBuffer &buffer) {
        TestBlock1.deserialize(buffer);
        NeighborBlock.deserialize(buffer);

    }
};


