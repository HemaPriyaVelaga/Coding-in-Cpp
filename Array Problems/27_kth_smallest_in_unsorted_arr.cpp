
#include<iostream> 
#include<climits> 
#include<cstdlib> 
using namespace std; 
  
int randomPartition(int arr[], int low, int high)
{
    int pivot = arr[high], i=low;
    for(int j=low;j<high;j++)
    {
        if(arr[j]<=pivot)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }
    }
    
    int temp = arr[i];
    arr[i] = arr[high];
    arr[high] = temp;
    
    return i;
}
  
// This function returns k'th smallest element in array1[l..r] using  
int findKthSmallest(int arr[], int low, int high, int k) 
{ 
     //Practise Yourself : Write your code Here 
     if(k>0 && k<=high-low+1)
     {
         int index = randomPartition(arr, low, high);
         if(index-low==k-1)
         {
             return arr[index];
         }
         else if(index-low > k-1)
         {
             return findKthSmallest(arr, low, index-1, k);
         }
         
         return findKthSmallest(arr, index+1, high, k-index+low-1);
     }
     return -1;
} 
  
  
int main() 
{ 
    int array1[] = {54, 26, 93, 17, 77, 31, 44,20,55}; // ans: 26
    int n = sizeof(array1)/sizeof(array1[0]), k = 3; 
    cout << "K'th smallest element is " << findKthSmallest(array1, 0, n-1, k); 
    return 0; 
}


/* Try more Inputs
case 1: 
actual = findKthElement([7, 10, 4, 3, 20, 15],0,5,3)
expected = 7

case2: 
 actual = findKthElement([7, 10, 4, 3, 20, 15],0,5,4)
 expected = 10
 
case3: 
actual = findKthElement([12, 3, 5, 7, 19],0,4,2)
expected = 5
*/
