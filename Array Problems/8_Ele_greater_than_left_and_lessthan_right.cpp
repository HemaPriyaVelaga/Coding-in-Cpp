#include <bits/stdc++.h> 
using namespace std; 
  
int max (int a, int b)
{
    if(a>b) return a;
    else return b;
}

int min(int a, int b)
{
    if(a<b) return a;
    else return b;
}

int findElement(int arr[], int n) 
{ 
   
    int left[n];
    left[0] = INT_MIN;
    
    for(int i=1;i<n;i++)
    {
        left[i] = max(arr[i-1], left[i-1]);
    }
    
    int right = INT_MAX;
    
    for(int i=n-1;i>=0;i--)
    {
        if(arr[i]>left[i] && arr[i]<right)
        {
            return i;
        }
        right = min(arr[i], right);
    }
    return -1; 
} 
  

int main() 
{ 
    int arr[] = {5, 1, 4, 4}; 
    int n = sizeof arr / sizeof arr[0]; 
    cout << "Index of the element is " << findElement(arr, n); 
    return 0; 
} 

/* Try more Inputs

findElement(array, length_of_array)


case1: 
actual = findElement([5, 1, 4, 3, 6, 8, 10, 7, 9],9)
expected = 4

case2: 
actual = findElement([6, 2, 5, 4, 7, 9, 11, 8, 10],9)
expected = 4

case3:
actual = findElement([5, 1, 4, 4],4)
expected = -1

*/
