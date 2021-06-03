#include<iostream>
using namespace std;
int maxDiff(int arr[], int n) {
  //Write your code here
  int maxdiff = 0, i, j;
  int right[n], left[n];
  
  right[n-1] = n-1;
  for(int j=n-2; j>=0;j--)
  {
      if(arr[j]>arr[right[j+1]])
      {
          right[j] = j;
      }
      else
      {
          right[j] = right[j+1];
      }
  }
  
  left[0] = 0;
  for(int i=1;i<n;i++)
  {
      if(arr[i]<arr[left[i-1]])
      {
          left[i] = i;
      }
      
      else
      {
          left[i] = left[i-1];
      }
      
  }
  
  i=0, j=0, maxdiff = -1;
  while(i<n && j<n)
  {
      if(arr[left[i]]<=arr[right[j]])
      {
          maxdiff = max(maxdiff, right[j] - left[i]);
          j++;
      }
      else
      {
          i++;
      }
  }
  
  
  
   return maxdiff;
}
int main() {
   int array[] = {9, 2, 3, 4, 5, 6, 7, 8, 18, 0};
   int n = sizeof(array) / sizeof(array[0]);
   cout<<"The maximum value of |arr[i] - arr[j]| + |i-j| is "<<maxDiff(array, n);
   return 0;
}
/* Try more Inputs
case1:
actual = findDiff([35, 9, 12, 3, 2, 70, 31, 33, 1])
expected = 6

case2:
actual = findDiff([1, 2, 3, 4, 5, 6])
expected = 5

case3:
actual = findDiff([9, 2, 3, 4, 5, 6, 7, 8, 18, 0])
expected = 8

case4:
actual = findDiff([6, 5, 4, 3, 2, 1])
expected = -1

*/
