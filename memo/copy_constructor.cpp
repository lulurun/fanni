/*
 * copy_constructor.cpp
 *
 *  Created on: Sep 2, 2009
 *      Author: lulu
 */

#include <iostream>
#include <string>

using namespace std;

class Object {
public:
	int a;
	string b;

	Object() {
		this->a = 1234;
		this->b = "test";
	}

	Object(int a, string b) {
		this->a = a;
		this->b = b;
	}

	Object(const Object &obj) {
		cout << "1 called" << endl;
		if (this != &obj) {
			(*this) = obj;
		}
	}

	Object &operator=(const Object &obj) {
		cout << "2 called" << endl;
		this->a = obj.a;
		this->b = obj.b;
		return *this;
	}

	void dump() const {
		cout << "\t\t" << this << endl;
		cout << "\t\t" << this->a << endl;
		cout << "\t\t" << this->b << endl;
	}
};

void real_obj_1(Object obj) {
	Object o = obj;
	o.dump();
}

void real_obj_2(Object obj) {
	Object &o = obj;
	o.dump();
}

void ref_obj_1(Object &obj) {
	Object o = obj;
	o.dump();
}

void ref_obj_2(Object &obj) {
	Object &o = obj;
	o.dump();
}

Object &ret_ref_obj_1() {
	Object *o = new Object();
	return *o;
}

Object ret_real_obj_1() {
	Object *o = new Object();
	return *o;
}

Object ret_real_obj_2() {
	Object o(23, "ko");
	return o;
}

int main() {
	{
		Object o(10, "qwert");
		cout << "1" << endl;
		real_obj_1(o);
		cout << "2" << endl;
		ref_obj_1(o);
		cout << "3" << endl;
		real_obj_2(o);
		cout << "4" << endl;
		ref_obj_2(o);
	}
	{
		cout << "5" << endl;
		Object o = ret_ref_obj_1();
		o.dump();
	}
	{
		cout << "6" << endl;
		Object &o = ret_ref_obj_1();
		o.dump();
	}
	{
		cout << "7" << endl;
		Object o = ret_real_obj_1();
		o.dump();
	}
	{
		cout << "8" << endl;
		const Object &o = ret_real_obj_1();
		o.dump();
	}
	{
		cout << "9" << endl;
		const Object &o = ret_real_obj_2();
		o.dump();
	}
	{
		cout << "10" << endl;
		Object o = ret_real_obj_2();
		o.dump();
	}
}

