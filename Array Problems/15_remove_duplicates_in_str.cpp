#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
   string removeDuplicates(string str) 
   {
     
      int arr[256] = {0};
      int n = size(str);
      int j=0;
      for(int i=0;i<n;i++)
      {
          if(arr[int(str[i])]==0)
          {
              arr[int(str[i])] = -1;
              str[j] = str[i];
              j++;
          }
          else if(arr[int(str[i])]==-1)
          {
              ;
          }
      }
      while(j<n)
      {
          str[j] = '\0';
          j++;
      }
      return str;
   }
};


int main(){
   Solution ob;
   string v = "bcabc";
   cout << ob.removeDuplicates(v);
}
