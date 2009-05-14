/*
 * test_FixedLengthBuffer.cpp
 *
 *  Created on: Apr 26, 2009
 *      Author: lulu
 */

#include <iostream>
#include "fanni/FixedLengthBuffer.h"

using namespace std;
using namespace Fanni;

int main() {
	FixedLengthBuffer buffer;
	for(int i=0; i< 10; i++) {
		buffer.putValue<int>(i+97);
	}
	cout << buffer.to_debug_string() << endl;

}
