
#include<iostream>
using namespace std;

void display(int *array, int size) 
{
   for(int i = 0; i<size; i++)
      cout << array[i] << " ";
   cout << endl;
}


void merge(int *arr,int *result, int low, int mid, int high) 
{
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
  
}

void mergeSort(int *arr,int *result, int low, int high)
{
   if(low==high)
   {
       return;
   }
   
   int mid = low + ((high-low)/2);
   
   mergeSort(arr, result, low, mid);
   mergeSort(arr, result, mid+1, high);
   merge(arr, result, low, mid, high);   
}

int main() 
{
   int arr[] ={8,4,3,12,25,6};
   int n = sizeof(arr)/sizeof(arr[0]);
   int result[n];
   mergeSort(arr,result, 0, n);     //(n-1) for last index
   cout << "Array after Sorting: ";
   display(arr, n);
}

