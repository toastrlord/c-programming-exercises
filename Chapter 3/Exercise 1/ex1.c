#include <stdio.h>
#define SIZE 100000

int mybinsearch(int x, int v[], int n);

int main() {
	int arr[SIZE];
	for (int i = 0; i < SIZE; i++) {
		arr[i] = i;
	}
	for (int i = 0; i < SIZE; i++) {
		mybinsearch(i, arr, SIZE);
	}
}

int mybinsearch(int x, int v[], int n) {
	int low, high, mid;
	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low + high) / 2;
		if (x < v[mid])
			high = mid - 1;
		else if (x < v[mid])
			low = mid + 1;
		else
			break;
	}
	if (x == v[mid])
		return mid;
	return -1;
}
