
#include <stdio.h>
#include<bits/stdc++.h>
using namespace std;

void findDistinctCount(int arr[], int n, int k)
{
	//Write your code here
	unordered_map<int, int> umap;
         //vector <int> dist_count;
         int count = 0;
         for (int i=0;i<k;i++)
         {
             if(umap[arr[i]]==0)
             {
                 count++;
             }
             umap[arr[i]]+=1;
         }
         cout<<count<<" ";
        // dist_count.push_back(count);
         
         for(int i=k;i<n;i++)
         {
             if(umap[arr[i-k]]==1)
             {
                 count--;
             }
             umap[arr[i-k]]-=1;
             
             if(umap[arr[i]]==0)
             {
                 count++;
             }
             umap[arr[i]]+=1;
             cout<<count<<" ";
             //dist_count.push_back(count);
         }
         //return dist_count;
}

int main(void)
{
	int arr[] = { 2, 1, 2, 3, 2, 1, 4, 5 }; // 3 3 4 5
	int k = 5;

	int n = sizeof(arr) / sizeof(arr[0]);
	findDistinctCount(arr, n, k);

	return 0;
}
/* Try more Inputs
case1:
actual = distinctElement([1,2,1,3,4,2,3],4)
expected = 3,4,4,3

case2:
actual = distinctElement([4,1,1],2)
expected = 2,1

case3:
actual = distinctElement([1,2,1,3,4,3],3)
expected = 2,3,3,2

case4:
actual = distinctElement([1,1,2,2],1)
expected = 1,1,2,2

*/
