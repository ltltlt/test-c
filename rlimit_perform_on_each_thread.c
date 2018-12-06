/*************************************************************************
	> File Name:		test2.c
	> Author:			ty-l1
	> Mail:				
	> Created Time:		2018-12-05 Wed 16:57
 ************************************************************************/

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *f(void *v) {
	char array[7][1024*1024];
	for (int i=0; i<7; i++)
		for (int j=0; j<1024*1024; j++)
			array[i][j] = j*12+i;
	sleep(60);
	return NULL;
}
int main()
{
	int max = 30;
	pthread_t tids[max];
	for (int i=0; i<max; i++) {
		pthread_create(&tids[i], NULL, f, (void*)(i%7+1));
	}
	for (int i=0; i<max; i++)
		pthread_join(tids[i], NULL);
	return 0;
}
