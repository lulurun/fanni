/*
 * unordered_map.cpp
 *
 *  Created on: Jan 20, 2009
 *      Author: lulu
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef vector<string> VECTOR_TYPE;

int main()
{
	vector<string> m;

	// add values
	m.push_back("Akira");
	m.push_back("Johnny");
	m.push_back("Millia");
    // list
    for(VECTOR_TYPE::iterator it=m.begin(); it!=m.end(); it++) {
    	cout << *it << endl;
    }

}

