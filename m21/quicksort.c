#include <stdio.h>

void print_array(int arr[], int size) {
	int index;

	for(index=0; index<size; index++) {
		printf("%d ",arr[index]);
	}
	printf("\n");
}

void swap(int *left, int *right) {
	int tmp = *left; 
		*left = *right; 
		*right = tmp;
}

int partition(int arr[], int left, int right) {
	int pivot, tmp, index;
	
	pivot = arr[right];
	tmp = left - 1;

	for (index=left; index<right; index++) {
		if (arr[index] <= pivot) {
			tmp++;
			swap(&arr[tmp], &arr[index]);
		}
	}

	swap(&arr[tmp+1], &arr[right]);
	return (tmp+1);
}

void quicksort(int arr[], int left, int right) {
	int pivot;

	if (left<right) {
		pivot = partition(arr, left, right);

		quicksort(arr, left, pivot-1);
		quicksort(arr, pivot+1, right);
	}
}

int main() {
	int arr[] = {3, 20, 42, 45, 63, 16, 33, 88, 34, 56};
	int size = sizeof(arr) / sizeof(arr[0]);
	
	printf("Printing the given array\n");
	(void) print_array(arr, size);

	quicksort(arr, 0, size-1);

	printf("Printing sorted array\n");
	(void) print_array(arr, size);

	return 0;
}
