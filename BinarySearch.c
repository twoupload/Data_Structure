#include <stdio.h>
#include <string.h>
int bsearch(int arr[], int len, int target) {
	int first = 0, last = len - 1, mid;
	while (first <= last) {
		mid = (first + last) / 2;
		if (target == arr[mid]) return mid;
		else {
			if (target < arr[mid]) last = mid - 1;
			else mid = first + 1;
		}
	}
	return -1;
}

int rbsearch(int arr[], int low, int high, int target) {
	int mid = (low + high) / 2;
	if (low > high) return -1;
	else {
		if (target == arr[mid]) return mid;
		else if (target < arr[mid]) rbsearch(arr, low, high - 1, target);
		else rbsearch(arr, low + 1, high, target);
	}
}
int rbsearch(int arr[], int low, int high, int target) {
	if (low > high) return -1;
	else {
		int mid = (low + high) / 2;
		if (target == mid) return mid;
		else if (target < arr[mid]) rbsearch(arr, low, mid - 1, target);
		else rbsearch(arr, mid + 1, high, target);
	}
}

