#include <bits/stdc++.h> 
using namespace std; 
  
int maxVal(int a, int b)
{
    if(a>b) return a;
    else return b;
}
  
// Returns minimum number of jumps 
// to reach array1[n-1] from array1[0] 
int minJumpToReachEnd(int arr[], int n) 
{ 
    int maxVal = arr[0], step = arr[0], jump = 1;
    
    for(int i=1;i<n;i++)
    {
        if(i==n-1)
        {
            return jump;
        }
        
        maxVal = max(maxVal, i+arr[i]);
        step--;
        
        if(step==0)
        {
            jump++;
            if(i>=maxVal)
            {
                return -1;
            }
            
            step = maxVal-i;
        }
    }
   
    return jump; 
} 
  

int main() 
{ 
    int array1[] = {3,2,1,0,4}; 
    int size = sizeof(array1) / sizeof(int); 
  
    cout <<  minJumpToReachEnd(array1, size); 
    return 0; 
} 

/* Try more Inputs
case 1: 
actual = minJumpToReachEnd([1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9],11)
expected = 3

case2: 
 actual = minJumpToReachEnd([1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1],10)
 expected = 10
 
case3: 
actual = minJumpToReachEnd([3,2,1,0,4],5)
expected = -1
Jump not possible
*/
