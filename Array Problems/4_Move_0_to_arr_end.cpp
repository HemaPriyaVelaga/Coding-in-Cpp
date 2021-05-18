#include <iostream> 
using namespace std; 
  
void moveZeroToTheEnd(int *arr, int n) 
{ 
   int j=0;
  
   for(int i=0;i<n-1;i++)
   {
       if(arr[i]!=0)
       {
           arr[j] = arr[i];
           j++;
       }
   }
  
   while(j<n)
   {
       arr[j]=0;
       j++;
   }
  
} 
  
int main() 
{ 
    int array1[] = {0, 1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0, 9}; 
    int n = sizeof(array1) / sizeof(array1[0]); 
    moveZeroToTheEnd(array1, n); 
    cout << "Result is :\n"; 
    for (int i = 0; i < n; i++) 
        cout << array1[i] << " "; 
    return 0; 
} 

/* Try more Inputs
case1:
 actual = MoveZeroToEnd([1,3,0,0,4,0,9],7)
 expected = [1,3,4,9,0,0,0]
 
case2:
actual = MoveZeroToEnd([0,1,0,3,12],5)
expected = [1,3,12,0,0]

case3:
actual = MoveZeroToEnd([0, 1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0, 9],13)
expected = [1,9,8,4,2,7,6,9,0,0,0,0,0]

*/
