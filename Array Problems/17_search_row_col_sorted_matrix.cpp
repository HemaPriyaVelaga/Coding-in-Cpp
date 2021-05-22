#include <bits/stdc++.h> 
   
using namespace std; 
   
bool matsearch(vector<vector<int>> arr, int rw, int cl, int x) 
{ 
   int i=0, j=cl-1;
   while(i<rw && cl>=0)
   {
       if(arr[i][j]==x)
       {
           return true;
       }
       if(arr[i][j]>x)
       {
           j--;
       }
       else
       {
           i++;
       }
   }
   
   return false;
} 
   

int main() 
{ 
    vector<vector<int>> mat = { { 10, 20, 30, 40, 50 }, 
                      { 15, 25, 35, 45, 60 }, 
                      { 27, 29, 37, 48, 70 }, 
                      { 32, 33, 39, 50, 80 } }; 
    cout<<matsearch(mat, 4, 5, 90); 
   
    return 0; 
} 

/* Try more Inputs

case1:
 actual = searchElement([[10, 20, 30, 40], 
		[15, 25, 36, 46], 
		[27, 29, 37, 48],
		[32, 33, 39, 50]],4,32)
 expected = True
 
case2:
actual = searchElement([[10, 20, 30, 40],
		[15, 25, 36, 46], 
		[27, 29, 37, 48], 
		[32, 33, 39, 50]],4,59)
expected = False

*/
