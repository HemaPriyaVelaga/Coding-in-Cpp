#include <iostream>
#include <vector>
using namespace std;

/*

Conditions:
1. Each student should get atleast one candy
2. Student with higher rating compared to the neighbours should get higher candies

*/

/*

Intuition:
1. if(arr[i-1]<arr[i]), then arr[i] must get one candy more than arr[i-1]  ------> checked using left array
2. if(arr[i+1]<arr[i]), then arr[i] must get one candy more than arr[i+1]  ------> checked using right array

*/

int min_candy(vector<int> & arr)
{
    unsigned long long int sum = 0;
    int n = arr.size();
    unsigned long long int left[n], right[n];
    fill(left, left+n, 1);
    fill(right, right+n, 1);
    
    for(int i=1;i<n;i++)
    {
        if(arr[i-1]<arr[i])
        {
            left[i] = left[i-1]+1;
        }
    }
    
     for(int i=n-2;i>=0;i--)
    {
        if(arr[i+1]<arr[i])
        {
            right[i] = right[i+1]+1;
        }
    }
    
    for(int i=0;i<n;i++)
    {
        sum+=max(left[i], right[i]);
    }
    
    
    return sum;
}




int main()
{
  std::vector<int> vect; 
vect.push_back(1); 
vect.push_back(5);
  vect.push_back(2);
   vect.push_back(1); 
   
   // 7 for {1 5 2 1}
   
  // vector <int> rating{23, 14, 15, 14, 56, 29, 14};  // 12
  vector <int> rating{10, 30, 20}; //4
  int result = min_candy(rating);
  cout<<result<<endl;
  
}
