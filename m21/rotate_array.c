#include <stdio.h>

void rotate_arr(int arr[], int len) {
	int temp;

	temp = arr[0];
	for(int i=0; i<len; i++) {
		arr[i] = arr[i+1];
	}
	arr[len-1] = temp;
}

int main() {
	int arr[] = {3, 4, 5, 6, 7, 8, 9};
	int temp, len, i, j, n;

	len = sizeof(arr) / sizeof(arr[0]);
	printf("Enter number of rotation\n");
	scanf("%d", &n);

	for(i=0;i < n; i++) {
			rotate_arr(arr, len);
	}
	
	for(i=0; i<len; i++)
		printf("%d", arr[i]);

	return 0;
}
