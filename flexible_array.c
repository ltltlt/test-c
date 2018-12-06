/*************************************************************************
	> File Name:		flexible_array.c
	> Author:			ty-l1
	> Mail:				
	> Created Time:		2018-11-14 Wed 15:16
 ************************************************************************/

#include <stdio.h>

typedef struct test {
	char c;
	int a[];
} test;

int main(int argc, const char *argv[])
{
	printf("%lu\n", sizeof(test));		// output 4, align, and flexible array not count in
	return 0;
}
