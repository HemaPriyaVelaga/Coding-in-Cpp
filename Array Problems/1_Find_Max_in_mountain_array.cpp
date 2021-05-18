#include <bits/stdc++.h> 
using namespace std; 
  
// CONCEPT USED: BINARY SEARCH

int findMaximumValue(int arr[], int low, int high)  
{  
    if(low==high)
    {
        return arr[low];
    }
    
    if(high==low+1)
    {
        if(arr[low]>=arr[high])
        {
            return arr[low];
        }
        else
        {
            return arr[high];
        }
    }
    
    int mid = low + ((high-low)/2);
    
    if(arr[mid-1]<arr[mid] && arr[mid]<arr[mid+1])
    {
        return findMaximumValue(arr, mid+1, high);
    }
    
    if(arr[mid-1]>arr[mid] && arr[mid]>arr[mid+1])
    {
        return findMaximumValue(arr, low, mid-1);
    }
    
    else
    {
        return arr[mid];
    }
    
    
    return 0;
}  
  

int main()  
{  
    int array1[] = {8, 10, 20, 80, 100, 200, 400, 500,1000, 3, 2, 1};  
    int n = sizeof(array1)/sizeof(array1[0]);  
    cout << "The maximum Value  is " << findMaximumValue(array1, 0, n-1);  
    return 0;  
} 
