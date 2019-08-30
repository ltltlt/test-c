/*************************************************************************
	> File Name:		grow_stack.c
	> Author:			ty-l1
	> Mail:				
	> Created Time:		2019-08-09 Fri 10:08
 ************************************************************************/

#include <stdio.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>

int count = 0;

void call() {
	if (count > 1000000) {
		return;
	}
	count++;
	int nums[100];
	for (int i=0; i<100; i++) {
		nums[i] = count + i;
	}
	struct timespec spec;
	spec.tv_sec = 0;
	spec.tv_nsec = 1000000;
	nanosleep(&spec, NULL);

	call();
}

int main(void) {
	printf("pid is: %d\n", getpid());
	call();
}
