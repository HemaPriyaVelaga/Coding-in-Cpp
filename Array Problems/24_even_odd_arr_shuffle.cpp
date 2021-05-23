#include <bits/stdc++.h>
using namespace std;


void sortArrayByParity(vector<int>& arr) 
    {
     
        int n = arr.size();
        int i=0, j=n-1;
        while(i<j)
        {
            if(arr[i]%2 && arr[j]%2==0)
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                //swap(arr[i], arr[j]);
                i++;
                j--;
            }
            else if(arr[i]%2==0)
            {
                i++;
            }
            else if(arr[j]%2)
            {
                j--;
            }
        }
       // return arr;
    }

int main()
{
  vector <int> arr = {3,1,2,4}
  //Now print the array using cout
  sortArrayByParity(arr)
  
  return 0;
  
}
