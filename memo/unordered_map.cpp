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

typedef unordered_map<string, int> MAP_TYPE;

int main()
{
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

