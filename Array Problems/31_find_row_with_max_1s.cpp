#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define M 5
#define N 5

int modified_binary_search(bool arr[],int low,int high)
{
    if(high>=low)
    {
        int mid = low + (high-low)/2;
        
       if((mid==0 || arr[mid-1]==0) && arr[mid]==1)
        {
            return mid;
        }
        else if(arr[mid]==0)
        {
            return modified_binary_search(arr, mid+1, high);
        }
        
        else return modified_binary_search(arr, low, mid-1);
    }
    return -1;
}

int findRowIndex(bool mat[][N])
{
	//Write your code here
	int max_row_ind = 0, min_index = INT_MAX;
	int i, index;
	for(int i=0;i<M;i++)
	{
	    index = modified_binary_search(mat[i], 0, N-1);
	    if(index!=-1 && index<min_index)
	    {
	        min_index = index;
	        max_row_ind = i;
	    }
	}
	return max_row_ind;
}

int main()
{
	bool mat[M][N] =
	{
		{ 0, 0, 0, 1, 1 },
		{ 0, 0, 1, 1, 1 },
		{ 0, 0, 0, 0, 0 },
		{ 0, 1, 1, 1, 1 },
		{ 0, 0, 0, 0, 1 }
	};

	int rowIndex = findRowIndex(mat);

	// rowIndex = 0 means no 1's are present in the matrix
	if (rowIndex)
		cout << "Maximum 1's are present in the row " << rowIndex;

	return 0;
}
/* Try more Inputs
case1:
 actual = findRow([[0, 1, 1, 1], 
       [0, 0, 1, 1], 
       [1, 1, 1, 1], 
       [0, 0, 0, 0]])
expected = 2

case2:
actual = findRow([[1, 1, 1], 
       [0, 0, 0], 
       [1, 1, 0], 
       [1, 0, 0]])
expected = 0

case3:
actual = findRow([[0, 0, 0, 1, 1], 
       [0, 0, 1, 1, 1], 
       [0, 0, 0, 0, 0], 
       [0, 1, 1, 1, 1],
       [0, 0, 0, 0, 1]])
expected = 4

*/
