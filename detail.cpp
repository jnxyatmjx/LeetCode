#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <cstdint>

void * thuc(void * index){
	cpu_set_t cpuMask;
 	intptr_t i = (intptr_t)index; //in 64-bit system (void *) have 8Bytes but (int) only have 4Bytes!!!
	CPU_ZERO(&cpuMask);
	CPU_SET(i,&cpuMask);
	pthread_setaffinity_np(pthread_self(), sizeof(cpuMask), &cpuMask);

	pthread_exit(NULL);
}

int main(int argc,char * argv[])
{
	(void)argc;(void)argv;
	int cpus = sysconf(_SC_NPROCESSORS_ONLN);printf("computers have %d cpus\n",cpus);
	thuc((void*)2);

exit(EXIT_SUCCESS);
}


