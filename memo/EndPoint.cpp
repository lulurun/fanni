/*
 * EndPoint.cpp
 *
 *  Created on: Sep 8, 2009
 *      Author: lulu
 */

#include "fanni/EndPoint.h"

using namespace Fanni;

class Obj {
	const EndPoint *ep;
public:
	Obj(const EndPoint *ep) : ep(ep) {}
	~Obj() {
		delete this->ep;
	}
};

int main() {
	EndPoint *ep = new EndPoint();
	Obj *o = new Obj(ep);
	delete o;
	return 0;
}
