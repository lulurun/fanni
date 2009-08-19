#include <iostream>

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <pthread.h>
#include <sys/time.h>
#ifdef SOLARIS /* needed with at least Solaris 8 */
#include <siginfo.h>
#endif

using namespace std;

void printStack(const char *where) {
	printf("%s stack: %p\n", where, &where);
}

void signalHandler(int cause, siginfo_t *HowCome, void *ptr) {
	printStack("signal handler 1");
}

void signalHandler_second(int cause, siginfo_t *HowCome, void *ptr) {
	printStack("signal handler 2");
}

void *threadStart(void *ptr) {
	int i;
	struct itimerval itimer;
	struct sigaction sa;
	sa.sa_sigaction = signalHandler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO; /* we want a siginfo_t */
	if (sigaction(SIGPROF, &sa, 0)) {
		perror("sigaction");
		exit(1);
	}
	itimer.it_interval.tv_sec = 0;
	itimer.it_interval.tv_usec = 100 * 1000;
	itimer.it_value.tv_sec=0;
	itimer.it_value.tv_usec=100 *1000;
	setitimer(ITIMER_PROF, &itimer, NULL);
	while(1) {
		;
	}
	return 0;
}

void *threadStart_second(void *ptr) {
	int i;
	struct itimerval itimer;
	struct sigaction sa;
	sa.sa_sigaction = signalHandler_second;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO; /* we want a siginfo_t */
	if (sigaction(SIGPROF, &sa, 0)) {
		perror("sigaction");
		exit(1);
	}
	itimer.it_interval.tv_sec = 0;
	itimer.it_interval.tv_usec = 2*100 * 1000;
	itimer.it_value.tv_sec=0;
	itimer.it_value.tv_usec=2*100 *1000;
	setitimer(ITIMER_PROF, &itimer, NULL);
	while(1) {
		;
	}
	return 0;
}

int main() {
	cout << "start timer 1" << endl;
	{
		pthread_t th;
		pthread_create(&th, NULL, threadStart, NULL);
	}
	cout << "start timer 2" << endl;
	{
		pthread_t th;
		pthread_create(&th, NULL, threadStart_second, NULL);
	}

	while(1) {
		;
	}
	return (0);
}
/*<@>
 <@> ******** Program output: ********
 <@> main routine stack: 0x7fffde863260
 <@> thread sigaction: 0x40800070
 <@> thread routine stack: 0x40800060
 <@> thread sigaction: 0x41001070
 <@> thread routine stack: 0x41001060
 <@> thread sigaction: 0x41802070
 <@> thread routine stack: 0x41802060
 <@> thread sigaction: 0x42003070
 <@> thread routine stack: 0x42003060
 <@> thread sigaction: 0x42804070
 <@> thread routine stack: 0x42804060
 <@> */
