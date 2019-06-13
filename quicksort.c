/*************************************************************************
	> File Name:		quicksort.c
	> Author:			ty-l1
	> Mail:				
	> Created Time:		2019-01-28 Mon 15:05
 ************************************************************************/

#include <stdio.h>

void swap(int array[], int i, int j) {
	int tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}

void quicksort(int array[], int start, int end) {
	if (end < start) return;
	int low = start, high = end;
	int key = array[start];
	while (start <= end) {
		while(start <= end && array[end] >= key)
			end --;
		if (start <= end)
			swap(array, start, end);
		while (start <= end && array[start] <= key) 
			start ++;
		if (start <= end)
			swap(array, start, end);
	}
	quicksort(array, low, start-1);
	quicksort(array, start+1, high);
}

int main() {
	int array[] = {3, 5, 1, 0, -2, -3, -2};
	int length = sizeof(array) / sizeof(int);
	quicksort(array, 0, length-1);

	for (int i=0; i<length; i++) {
		printf("%d\n", array[i]);
	}
}
