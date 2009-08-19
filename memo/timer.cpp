/*
 * time.cpp
 *
 *  Created on: Aug 17, 2009
 *      Author: lulu
 */

#include <sys/select.h>
#include <iostream>
#include <ctime>
#include <cstdio>

using namespace std;

/* 1. get unix time */
void get_unix_time() {
	cout << "sizeof time_t: " << sizeof(time_t) << endl;
	cout << "sizeof clock_t: " << sizeof(clock_t) << endl;
	cout << "sizeof timespec: " << sizeof(timespec) << endl;
	time_t t = time(NULL);
	cout << "current time: " << t << endl;
}

/* 2. usleep() */
int my_usleep(long usec) {
	timeval delay;
	delay.tv_sec = usec / 1000000L;
	delay.tv_usec = usec % 1000000L;
	return select( 0, NULL, NULL, NULL, &delay );
}

int test_usleep() {
	{
		clock_t a = std::clock();
		clock_t b = std::clock();
		cout << "nothing" << endl;
		cout << "a: " << a << " b: " << b << endl;
	}
	{
		clock_t a = std::clock();
		::usleep(500000);
		clock_t b = std::clock();
		cout << "usleep" << endl;
		cout << "a: " << a << " b: " << b << endl;
	}
	{
		clock_t a = std::clock();
		::sleep(1);
		clock_t b = std::clock();
		cout << "sleep" << endl;
		cout << "a: " << a << " b: " << b << endl;
	}
	{
		clock_t a = std::clock();
		::my_usleep(500000);
		clock_t b = std::clock();
		cout << "my_usleep" << endl;
		cout << "a: " << a << " b: " << b << endl;
	}
	{
		clock_t a = std::clock();
		for (int i = 0; i < 1000* 1000* 10 ; i ++) {
			;
		}
		clock_t b = std::clock();
		cout << "a: " << a << " b: " << b << endl;
	}
}

/* 3. better */
void better_timers() {
	timespec a, b;
	clock_gettime(CLOCK_REALTIME, &a);
	::usleep(500000);
	clock_gettime(CLOCK_REALTIME, &b);
	cout << "gettime" << endl;
	cout << "a: " << a.tv_sec << " " << a.tv_nsec << endl;
	cout << "b: " << b.tv_sec << " " << b.tv_nsec << endl;
}


int main() {
	get_unix_time();
	test_usleep();
	better_timers();
	return 0;
}

