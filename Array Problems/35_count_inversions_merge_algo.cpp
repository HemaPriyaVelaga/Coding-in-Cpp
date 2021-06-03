
#include <iostream>
using namespace std;


int merge(int *arr,int *result, int low, int mid, int high) 
{
   int inversion_count = 0;
   int k=low, i=low, j=mid+1;
   
   while(i<=mid && j<=high)
   {
       if(arr[i]<=arr[j])
       {
           result[k++] = arr[i++];
       }
       else
       {
           result[k++] = arr[j++];
           inversion_count = inversion_count + (mid+1 -i);
       }
  }
  
  while(i<=mid)
  {
      result[k++] = arr[i++];
  }
  
  while(j<=high)
  {
      result[k++] = arr[j++];
  }
   
  for(i=low;i<=high;i++)
  {
      arr[i] = result[i];
  }
  return inversion_count;
}

int mergeSort(int *arr,int *result, int low, int high)
{
   int inversion_count = 0;
   if(low==high)
   {
       return 0;
   }
   
   int mid = low + ((high-low)/2);
   
   inversion_count+=mergeSort(arr, result, low, mid);
   inversion_count+=mergeSort(arr, result, mid+1, high);
   inversion_count+=merge(arr, result, low, mid, high);   
   
   return inversion_count;
}


int arrayInversion(int array1[], int n) {
    //Practise Yourself : Write your code Here
    return 0;
}
int main() {
  // int array1[] = {9, 1, 6, 4, 5}; //4
    int array1[] = {8, 4, 2, 1}; //4
   int n = 4;
   int temp [n];
   cout << "Number of inversions are "<< mergeSort(array1,temp,0, n-1);
}


/* Try more Inputs
case 1: 
actual = arrayInversion([3, 2, 1],3)
expected = 3

case2: 
 actual = arrayInversion([4, 1, 3, 2],4)
 expected = 4
 
case3: 
actual = arrayInversion([8, 4, 2, 1],4)
expected = 6
*/
