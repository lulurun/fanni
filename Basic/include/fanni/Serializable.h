#ifndef SERIALIZABLE_H_
#define SERIALIZABLE_H_

namespace Fanni {

template<class BufferType>
class Serializable {
public:
	Serializable() {};
	virtual ~Serializable() {};

	virtual void serialize(BufferType &buffer) const = 0;
	virtual void deserialize(BufferType &buffer) = 0;
};

}

#endif /* SERIALIZABLE_H_ */
