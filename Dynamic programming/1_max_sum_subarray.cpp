#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Function to find contiguous sub-array with the largest sum
// in given set of integers
int kadane(int arr[], int n)
{
  //Write your code here
  int resultsum=INT_MIN, intersum = 0;
  for(int i=0;i<n;i++)
  {
      intersum= intersum+arr[i];
     /* if(intersum<0)
      {
          intersum = 0;
      } */
      
      if(arr[i]>intersum)
      {
          intersum = arr[i];
      }
      
      if(intersum>resultsum)
      {
          resultsum = intersum;
      }
      
      
  }
  return resultsum;
//	return 0;
}

int main()
{
	int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 }; // output = 6
	int n = sizeof(arr)/sizeof(arr[0]);

	cout << "The sum of contiguous sub-array with the largest sum is " <<
			kadane(arr, n);

	return 0;
}

/* Try more Inputs

case1:
actual = maxSubArraySum([-2,1,-3,4,-1,2,1,-5,4],9)
expected = 6

case2:
actual = maxSubArraySum([1],1)
expected = 1

case3:
actual = maxSubArraySum([-4, 2, -5, 1, 2, 3, 6, -5, 1],9)
expected = 12

case4:
actual = maxSubArraySum([-5, 6, -7, 1, 4, -8, 16],7)
expected = 16

*/
