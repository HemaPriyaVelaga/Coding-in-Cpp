#include <iostream> 
#include <cstring> 
#include <algorithm> 
#include <bits/stdc++.h>
using namespace std; 
  

void swap(char *a, char *b) 
{ 
    char temp = *a; 
    *a = *b; 
    *b = temp; 
} 
  
// Given a number as a char array array1[], this function finds the 
// next greater number.  It modifies the same array to store the result 
void findNext(char arr[], int n) 
{ 
     
    int i=n-1;
    for(i=n-1;i>0;i--)
    {
        if(arr[i-1]<arr[i])
        {
            break;
        }
    }
        int swap_ele = arr[i-1], min_index = i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]>swap_ele && arr[j]<arr[min_index])
            {
                min_index = j;
            }
        }
        
        swap(arr[i-1], arr[min_index]);
        sort(arr+i, arr+(n));
        
        for(int i=0;i<n;i++)
        {
            cout<<arr[i]<<" ";
        }
    return; 
} 
  
int main() 
{ 
    char digits[] = "6938652"; 
    int n = strlen(digits); 
    findNext(digits, n); 
    return 0; 
} 


/* Try more Inputs
case 1: 
actual = findNextNumber([1,2,3,4],4)
expected = 1243

case2: 
 actual = findNextNumber([5,3,4,9,7,6],6)
 expected = 536479
 
case3: 
actual = findNextNumber([6,9,3,8,6,5,2],7)
expected = 6952368
*/
