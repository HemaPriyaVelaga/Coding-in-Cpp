#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int count_single (vector <int> arr, int n)
{
    int exor_sum = 0;
    for(int i=0;i<n;i++)
    {
        exor_sum = (exor_sum^arr[i]);
    }
    return exor_sum;
}
int main() {
   //Practise Yourself : Write your code Here
   vector <int> arr = {9,4,9,6,4};
   int n = arr.size();
   cout<<count_single(arr, n);
   return 0;
}

/* Try more Inputs
case 1: 
actual = main([-1,2,-1,3,2])
expected = 3

case2: 
 actual = main([9,4,9,6,4])
 expected = 6
 
case3: 
actual = main([1,1,2,2,3,3,4])
expected = 4
*/
