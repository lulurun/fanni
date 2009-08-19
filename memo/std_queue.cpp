/*
 * std_queue.cpp
 *
 *  Created on: Aug 16, 2009
 *      Author: lulu
 */

#include <queue>
#include <string>
#include <iostream>

using namespace std;

class Object {
public:
	string name;
	int number;
	Object(string name, int number) : name(name), number(number) {}
};

int main() {
	queue<Object *> queue;
	queue.push(new Object("test1", 1));
	queue.push(new Object("test2", 2));
	queue.push(new Object("test3", 3));
	queue.push(new Object("test4", 4));
	// size
	cout << "empty: " << queue.empty() << endl;
	cout << "size: " << queue.size() << endl;
	// pop
	while(queue.front() != NULL) {
		cout << "empty: " << queue.empty() << endl;
		cout << "size: " << queue.size() << endl;
		cout << queue.front()->name << endl;
		queue.pop();
	}
	cout << "empty: " << queue.empty() << endl;
	cout << "size: " << queue.size() << endl;
	return 0;
}

