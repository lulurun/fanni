/*
 * unordered_map.cpp
 *
 *  Created on: Jan 20, 2009
 *      Author: lulu
 */

#include <iostream>
#include <string>
#include <tr1/unordered_map>

using namespace std;
using namespace std::tr1;

class Object {
public:
	string name;
	int number;

	Object() {
		cout << "ctor 0" << endl;
	};
	Object(string name, int number) : name(name), number(number) {
		cout << "ctor 1" << endl;
	};
	~Object(){
		cout << "Object " << this->name << " deleted" << endl;
	};
};

void object_erase_memo() {
	typedef unordered_map<int, Object> OBJECT_MAP_TYPE;
	OBJECT_MAP_TYPE m;
	cout << "create objects" << endl;
	Object *obj1 = new Object("test1", 1);
	//Object *obj2 = new Object("test2", 2);
	Object *obj3 = new Object("test3", 3);
	cout << "add to map" << endl;
	m[1] = *obj1;
	cout << "added 1" << endl;
	/*
	m[2] = *obj2;
	cout << "added 2" << endl;
	*/
	m[3] = *obj3;
	cout << "added 3" << endl;
	cout << "erase begin" << endl;
	m.erase(3);
	m.erase(4);
	cout << "erase end" << endl;
	// list
	for(OBJECT_MAP_TYPE::iterator it=m.begin(); it!=m.end(); it++) {
		cout << it->first << " => " << it->second.name << endl;
	}
}

void object_ptr_erase_memo() {
	typedef unordered_map<int, Object *> OBJECT_PTR_MAP_TYPE;
	OBJECT_PTR_MAP_TYPE m;
	cout << "create objects" << endl;
	Object *obj1 = new Object("test1", 1);
	Object *obj2 = new Object("test2", 2);
	Object *obj3 = new Object("test3", 3);
	cout << "add to map" << endl;
	m[1] = obj1;
	m[2] = obj2;
	m[3] = obj3;
	cout << "erase begin" << endl;
	m.erase(3);
	cout << "erase end" << endl;
    // list
    for(OBJECT_PTR_MAP_TYPE::iterator it=m.begin(); it!=m.end(); it++) {
    	cout << it->first << " => " << it->second->name << endl;
    }
}

void object_memo() {

	typedef unordered_map<Object *, int> PACKET_MAP_TYPE;
	PACKET_MAP_TYPE m;
	Object *obj1 = new Object("test1", 1);
	Object *obj2 = new Object("test2", 2);
	Object *obj3 = new Object("test3", 3);

	m[obj1] = 1;
	m[obj2] = 2;
	m[obj3] = 3;

    // count
    cout << m.size() << endl;
    // list
    for(PACKET_MAP_TYPE::iterator it=m.begin(); it!=m.end(); it++) {
    	cout << it->first->name << " => " << it->second << endl;
    }
    // cout with register
    {
    	Object *key = new Object("test3", 4);
    	cout << m[key] << endl; // 23
    }
    // found
    {
    	PACKET_MAP_TYPE::const_iterator it = m.find(obj3);
		if (it == m.end()) {
			cout << obj3->name << " not found" << endl;
		} else {
			cout << it->first << " => " << it->second << endl;
		}
    }
}

void string_memo() {
	typedef unordered_map<string, int> MAP_TYPE;
	MAP_TYPE m;

	// add values
    m["Akira"]  = 23;
    m["Johnny"] = 38;
    m["Millia"] = 16;
    // count
    cout << m.size() << endl;
    // list
    for(MAP_TYPE::iterator it=m.begin(); it!=m.end(); it++) {
    	cout << it->first << " => " << it->second << endl;
    }
    // cout with register
    {
    	cout << m["unknown"] << endl; // 23
    }
    // found
    {
		string key = "Akira";
		MAP_TYPE::const_iterator it = m.find(key);
		if (it == m.end()) {
			cout << key << " not found" << endl;
		} else {
			cout << it->first << " => " << it->second << endl;
		}
    }
    // not found
    {
		string key = "test";
		MAP_TYPE::const_iterator it = m.find(key);
		if (it == m.end()) {
			cout << key << " not found" << endl;
		} else {
			cout << it->first << " => " << it->second << endl;
		}
    }
    // erase member
    {
    	m.erase("Akira");
        for(MAP_TYPE::iterator it=m.begin(); it!=m.end(); it++) {
        	cout << it->first << " => " << it->second << endl;
        }
    }
    // erase unkown
    {
    	m.erase("kuku");
        for(MAP_TYPE::iterator it=m.begin(); it!=m.end(); it++) {
        	cout << it->first << " => " << it->second << endl;
        }
    }
}

int main() {
	object_ptr_erase_memo();
}

