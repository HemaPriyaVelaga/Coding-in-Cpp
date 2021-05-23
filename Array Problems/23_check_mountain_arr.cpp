#include <bits/stdc++.h>
using namespace std;

bool validMountainArray(vector<int>& arr) {
        
        int n = arr.size();
        if(n<=1) return false;
        int peak, i=0;
        while(arr[i]<arr[i+1] && i<n)
        {
            i++;
        }
        peak = i;
        cout<<"Peak index is: "<<peak<<endl;
        if(peak==n-1 || peak==0) 
        {
            cout<<"Peak is end"<<endl;
            return false;
            
        }
        for(int i=0;i<peak-1;i++)
        {
            if(arr[i]>=arr[i+1])
            {
                cout<<"Checking up: ";
                cout<<arr[i]<<" "<<arr[i+1];
                return false;
            }
        }
         if(arr[peak+1] == arr[peak]) return false;
        for(int i=peak+1;i<n-1;i++)
        {
           
            if(arr[i]<=arr[i+1])
            {
                cout<<"Checking down: ";
                cout<<arr[i]<<" "<<arr[i+1];
                return false;
            }
        }
        return true;
    }



int main()
{
  vector <int> arr = {0,3,2,1} //true

  cout<<validMountainArray(arr);
  return 0;

}
