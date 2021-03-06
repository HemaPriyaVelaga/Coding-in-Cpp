#include <iostream>

// Recursive implementation of Binary Search Algorithm to return
// the position of target x in an array

int binarySearch(int arr[], int low, int high, int key)
{
    //Practise Yourself : Write your code Here
    if(low>high)
    {
        return -1;
    }
    
    int mid = low + ((high-low)/2); // this formula is used to eliminate the integer overflow caused when high+low is a very high value.
    
    if(arr[mid]==key)
    {
        return mid;
    }
    
    else if(key<arr[mid])
    {
        return binarySearch(arr, low, mid-1, key);
    }
    
    else
    {
        return binarySearch(arr, mid+1,high, key);
    }
    
}

// Non recursive binary search using while loop

/*

int binarySearch(vector<int>& nums, int target){
  if(nums.size() == 0)
    return -1;

  int left = 0, right = nums.size() - 1;
  while(left <= right){
    // Prevent (left + right) overflow
    int mid = left + (right - left) / 2;
    if(nums[mid] == target){ return mid; }
    else if(nums[mid] < target) { left = mid + 1; }
    else { right = mid - 1; }
  }

  // End Condition: left > right
  return -1;
}

*/

int main()
{
    int array[] = { 2, 5, 6, 8, 9, 10 };
    int target = 11;
 
    int n = sizeof(array)/sizeof(array[0]);
 
    int low = 0, high = n - 1;
    int index = binarySearch(array, low, high, target);
 
    if (index != -1)
        printf("Element found at index %d", index);
    else
        printf("Element not found in the array");
 
    return 0;
}
