#include <bits/stdc++.h>
using namespace std;


class Solution {
   public:
  // This function returns the length of the de-duplicated array along with performing the de-duplication
   int removeDuplicates(vector<int> &arr) {
      
      int n = arr.size(), j=0;
      for(int i=0;i<n-1;i++)
      {
          if(arr[i]!=arr[i+1])
          {
              
              arr[j] = arr[i];
              j++;
          }
      }
      arr[j++] = arr[n-1];
      return j;
   }
};


int main(){
   Solution ob;
   vector<int> v = {2, 2, 2, 2, 3,4,4,4,4};
   int n = ob.removeDuplicates(v);
   cout <<"New array size: "<<n<<endl;
   for(int i=0;i<n;i++)
   {
       cout<<v[i]<<" ";
   }
}

/* Try more Inputs

case1:
actual = removeDuplicates([1,1,2])
expected = 2

case2:
actual = removeDuplicates([2, 2, 2, 2, 2])
expected = 1

case3:
actual = removeDuplicates([1, 2, 2, 3, 4, 4, 4, 5, 5])
expected = 5

case4:
actual = removeDuplicates([1,2,3,4,5])
expected = 5

*/
