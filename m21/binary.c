#include <stdio.h>

int binary_search(int [], int, int, int);

int main() {
	int arr[] = {4, 6, 22, 33, 44, 55, 77, 89};
	int left, right, result, value, len_of_arr;

	printf("Enter the value to search from ordered array\n");
	scanf("%d", &value);

	left = 0;
	len_of_arr = sizeof(arr) / sizeof(arr[0]);
	right = len_of_arr - 1;

	result = binary_search(arr, left, right, value);
	if (result != -1)
		printf("Element found at %d\n", result);
	else
		printf("Not found\n");

	return 0;
}

int binary_search(int arr[], int left, int right, int value) {
	
	int mid = left + (right - left) / 2;

	if (right >= left) {
		if (arr[mid] == value) {
			return mid;
		}

		if (arr[mid] > value) {
			right = mid -1;
			return binary_search(arr, left, right, value);
		}

			left = mid + 1;
			return binary_search(arr, left, right, value);
	}

	return -1;
}
