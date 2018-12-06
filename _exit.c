/*************************************************************************
	> File Name:		_exit.c
	> Author:			ty-l1
	> Mail:				
	> Created Time:		2018-12-06 Thu 11:46
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void f() {
	printf("hello world");		// if add a \n, it will output immediately, because when glibc sees a \n, it will flush it's stdout buffer
	switch(fork()) {
		case 0:
		// if call exit, it will flush glibc io buffer(not affect io operation using write or read)
		// execute exit handlers(registered using atexit)
		// because exit is a glibc function
		// but _exit is a system call, it will not do glibc stuff
			_exit(1);
		default:
			sleep(2);
	}
}
int main()
{
	f();
	return 0;
}
