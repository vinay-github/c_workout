#include <stdio.h>

int arr[] = {22, 33, 44, 55, 66, 77, 88};
int value;

int check(int mid) {
	if (value <= arr[mid])
		return 1;
	else
		return 0;
}

int binary_search(int left, int right) {
	int mid;
	
	while(left < right) {
		mid = (left + right) / 2;
		
		if(check(mid)) {
			right = mid;
		}
		else
			left = mid+1;
	}
	
	if (arr[left] == value)
		return left;
	else
		return -1;
}

int main() {
	int result;

	printf("Enter the value to search\n");
	scanf("%d", &value);
	
	result = binary_search(0, (sizeof(arr) / sizeof(arr[0])));
	
	if (result != -1) {
		printf("Found at %d (index)\n", result);
	}
	else
		printf("Not found\n");

	return 0;
	
}
