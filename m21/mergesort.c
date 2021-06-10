#include <stdio.h>

void merge(int arr[], int left, int mid, int right) {
	int n1, n2;
	int i, j, k;
	
	n1 = mid - left + 1;
	n2 = right - mid;

	int la[n1], ra[n2];

	for (i=0; i<n1; i++)
		la[i] = arr[left+i];
	for (j=0; j<n2; j++)
		ra[j] = arr[mid+j+1];

	i = 0, j = 0, k = left;

	while(i<n1 && j<n2) {
		if(la[i] <= ra[j]) {
			arr[k] = ra[j];
			i++;
		}
		else {
			arr[k] = la[i];
			j++;
		}
		k++;
	}

	while(i<n1) {
		arr[k++] = la[i++];
	}

	while(j<n2) {
		arr[k++] = ra[j++];
	}
}


void mergesort(int arr[], int left, int right) {
	int mid;
	
	if (left < right) {
		mid = left + (right-left)/2;

		mergesort(arr, left, mid);
		mergesort(arr, mid+1, right);

		merge(arr, left, mid, right);
	}
}

void print_array(int arr[], int size) {
	int index;

	for(index=0; index<size; index++) {
		printf("%d ", arr[index]);
	}
	printf("\n");
}

int main() {
	int arr[] = {33, 55, 23, 45, 7, 45, 65, 99, 34, 12, 21, 62};
	int size = sizeof(arr) / sizeof(arr[0]);


	printf("Printing array\n");
	print_array(arr, size);

	mergesort(arr, 0, size-1);

	printf("Printing array after mergesort\n");
	print_array(arr, size);

	return 0;
}
