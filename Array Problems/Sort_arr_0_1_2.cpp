#include<bits/stdc++.h> 
using namespace std; 
  
void swap(int *a, int *b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 

void segregateArray(int arr[], int n) 
{ 
    int i, low=0, mid =0, high = n-1; 
    for(int i=0;i<n;i++)
    {
        if(arr[mid]==2)
        {
            swap(arr[mid], arr[high]);
            high--;
        }
        else if(arr[mid]==0)
        {
            swap(arr[mid], arr[low]);
            mid++;
            low++;
        }
        else
        {
            mid++;
        }
    }
    for (i = 0; i < n; i++) 
        cout << arr[i] << " "; 
 
} 

int main() 
{ 
    int array1[] = {0, 1, 2, 0, 1, 2}; 
    int arr_size = sizeof(array1)/sizeof(array1[0]); 
    int i;   
    cout << "segregated array "; 
    segregateArray(array1, arr_size);  
    return 0; 
} 


/* Try more Inputs
case 1: 
actual = Sort012([0, 1, 2, 0, 1, 2],5)
expected = [0, 0, 1, 1, 2, 2]

case2: 
 actual = Sort012([0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1],11)
 expected = [0,0,0,0,0,1,1,1,1,1,2,2]
 
case3: 
actual = Sort012([2,0,1}],3)
expected = [0,1,2]
*/
