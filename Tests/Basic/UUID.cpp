/*
 * UUID.cpp
 *
 *  Created on: Aug 30, 2009
 *      Author: lulu
 */

#include <iostream>
#include "fanni/UUID.h"

using namespace std;
using namespace Fanni;

int main() {
	UUID z =UUIDGeneratorSingleton::get().Zero();
	cout << "*" << z.toString() << "*" << endl;

	{
		UUID a =UUIDGeneratorSingleton::get().Create();
		cout << "*" << a.toString() << "*" << endl;
	}
	{
		UUID a =UUIDGeneratorSingleton::get().Create();
		cout << "*" << a.toString() << "*" << endl;
	}
	{
		UUID a =UUIDGeneratorSingleton::get().Create();
		cout << "*" << a.toString() << "*" << endl;
	}
	{
		UUID a =UUIDGeneratorSingleton::get().Create();
		cout << "*" << a.toString() << "*" << endl;
	}
	{
		UUID a =UUIDGeneratorSingleton::get().Create();
		cout << "*" << a.toString() << "*" << endl;
	}
	{
		UUID a =UUIDGeneratorSingleton::get().Create();
		cout << "*" << a.toString() << "*" << endl;
	}
}

