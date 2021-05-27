#include <bits/stdc++.h> 
using namespace std; 
  
int storeWater(int arr[], int n) 
{ 
     //Practise Yourself : Write your code Here
     int maxleft[n], maxright[n];
     maxright[n-1] = arr[n-1];
     for(int i=n-2;i>=0;i--)
     {
         maxright[i] = max(arr[i], maxright[i+1]);
     }
     
     maxleft[0] = arr[0];
     for(int i=1;i<n;i++)
     {
         maxleft[i] = max(arr[i], maxleft[i-1]);
     }
     
     int result[n];
     int sum = 0;
     for(int i=1;i<n-1;i++)
     {
         result[i] = min(maxleft[i], maxright[i]) - arr[i];
         sum+=result[i];
     }
     return sum;
} 
  
int main() 
{ 
    int array1[] = { 5,3,4,6,3,6 }; // sol is 6
    int n = sizeof(array1) / sizeof(array1[0]); 
    cout << "Maximum water that can be stored is "
         << storeWater(array1, n); 
    return 0; 
}
