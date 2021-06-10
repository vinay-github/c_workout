#include <stdio.h>
#include <stdlib.h>

void print_array(int [], int);
void array_rotation(int [], int);

int main() {
	int arr[] = { 4, 7, 2, 33, 55, 22, 76, 12, 23, 44, 53, 21 }, value, size;
	size = sizeof(arr)/sizeof(arr[0]);

	printf("-----------------------------------------------------\n");
	printf("Array: ");
	print_array(arr, size);
	printf("-----------------------------------------------------\n");

	printf("1. Program for array rotation\n\n");
	printf("Enter your choice: ");
	scanf("%d", &value);
	printf("-----------------------------------------------------\n");
	
	switch(value) {
		case 1:
			array_rotation(arr, size);
			break;
		default:
			printf("Invalid choice\n");
			exit(EXIT_FAILURE);
	}

	return 0;
}

void print_array(int arr[], int size) {
	for(int i=0; i<size; i++) 
		printf("%d ", arr[i]);
	printf("\n");
}	

void array_rotation(int arr[], int size) {
	int no_of_rotations;
	int rotated_arr[size], index=0;

	printf("Enter the number of rotations: ");
	scanf("%d", &no_of_rotations);

	if(no_of_rotations < 0) {
		printf("Can't rotate\n");
		exit(EXIT_FAILURE);
	}


	for (int i=(size-no_of_rotations); i<size; i++)
		rotated_arr[index++] = arr[i];

	for (int i=0;i<(size-no_of_rotations);i++)
		rotated_arr[index++] = arr[i];

	print_array(rotated_arr, size);
}
