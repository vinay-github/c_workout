/* linear search program using C */
#include <stdio.h>
#include <ctype.h>

int linear_search(int[], int, int);
int binary_search(int arr[], int left, int right, int value);

int main()
{
	int arr[] = { 3, 4, 9, 6, 11, 45, 20,77 };
	int arr1[] = {5, 8, 13, 45, 55, 77, 89, 123 };
	int value = 0, result = 0, option;
	int length = 0;
	int left, right;
	
	printf("1. Linear Search\n2. Binary Search\n3. Exit\n");
	scanf("%d", &option);

	switch(option)
	{
		case 1:
			printf("Enter the value to search in the array\n");
			scanf("%d", &value);
			length = (int) sizeof(arr) / sizeof(arr[0]);
			result = linear_search(arr, value, length);
			break;

		case 2:
			printf("Enter the value to search in the array\n");
			scanf("%d", &value);
			
			left = 0;
			right = sizeof(arr1) / sizeof(arr1[0]);
			result = binary_search(arr1, left, right-1, value);
			break;
			
		case 3:
			printf("Exiting...\n");
			return 0;
		default:
			printf("Invalid option selected\n");
			main();
			
	}

	
	if(result != -1) {
		printf("Found at index %d\n", result);
	} else {
		printf("Not found\n");	
	}
	//result = search(arr, value, )
	return 0;

}

int linear_search(int arr[], int value, int length)
{
	int index, position = -1, left, right;
	
	right = length -1;
	left = 0;
	
	for(index=0; index<length; index++)
	{
		if(arr[right] == value)
		{
			position = right;
			break;
		}
		if(arr[left] == value)
		{
			position = left;
			break;
		}
			
		left++;
		right--;
		
	}
	if (position > -1) 
		return position;
	else 
		return -1;
}

int binary_search(int arr[], int left, int right, int value)
{
	int mid;
	if (right >= left)
	{
		mid = left + (right-left) / 2;
		if (arr[mid] == value)
			return mid;
		
		if (arr[mid] > value)
		{
			return binary_search(arr, left, mid-1, value);		
		}
		
		if (arr[mid] < value)
		{
			return binary_search(arr, mid+1, right, value);		
		}
	}
	return -1;

}
















