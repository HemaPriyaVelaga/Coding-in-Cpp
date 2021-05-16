#include <stdio.h>

// Function to find an element x in a circularly sorted array i.e., a sorted and rotated array
// Uses Binary Search Concept

int findNum(int arr[], int start, int end, int key) 
{
    if(start>end)
    {
        return -1;
    }
    
    int mid = start + ((end-start)/2);
    
    if(arr[mid]==key)
    {
        return mid;
    }
    
    if(arr[start]<=arr[mid])
    {
        if(key>=arr[start] && key<=arr[mid])
        {
            return findNum(arr, start, mid-1, key);
        }
      
        return findNum(arr, mid+1, end, key);
    }
    
    if(key>=arr[mid] && key<=arr[end])
    {
        return findNum(arr, mid+1, end, key);
    }
    
    return findNum(arr, start, mid-1, key);
}


int arraySearch(int array1[], int n, int x)
{
  return findNum(array1, 0, n-1, x);  
}

int main(void)
{
	int array1[] = {3, 4, 5, 6, 7, 8, 9, 10, 1, 2};
	int target = 28;

	int n = sizeof(array1)/sizeof(array1[0]);
	int index = arraySearch(array1, n, target);

	if (index != -1)
		printf("Element found at index %d", index);
	else
		printf("Element not found in the array");

	return 0;
}
