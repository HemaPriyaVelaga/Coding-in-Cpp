#include <stdio.h> 
#include <stdlib.h> 
#include <bits/stdc++.h>
  
using namespace std;

int findNumberOfTriangles(int arr[], int n) 
{ 

    sort(arr, arr+n);
    int count = 0;
    for(int i=0;i<n-2;i++)
    {
        int k=i+2;
        for(int j=i+1;j<n;j++)
        {
            
            while(k<n && arr[i]+arr[j]>arr[k])
            {
                k++;
            }
            
            count+=(k-1-j);
        }
        
    }
    
  
    return count; 
} 
  
int main() 
{ 
    //int arr[] = {10, 21, 22, 100, 101, 200, 300}; //6
    int arr[] = {12, 35, 38, 90, 95, 250, 255};
    
    int size = sizeof( arr ) / sizeof( arr[0] ); 
  
    printf("Total number of triangles possible is %d ", 
        findNumberOfTriangles( arr, size ) ); 
  
    return 0; 
} 

/* Try more Inputs

case1:
actual = TriangleCount([12, 35, 38, 90, 95, 250, 255])
expected = 9

case2:
actual = TriangleCount([2,2,3,4])
expected = 3

case3:
actual = TriangleCount([4, 6, 3, 7])
expected = 3

case4:
actual = TriangleCount([10, 21, 22, 100, 101, 200, 300])
expected = 6

*/
