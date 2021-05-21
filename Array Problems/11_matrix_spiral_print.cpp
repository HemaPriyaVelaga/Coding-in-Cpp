#include <iostream>
using namespace std;

// #define M 5
// #define N 5

void printSpiral(int matrix[][N], int r, int c)
{
	 //Practise Yourself : Write your code Here
	int top = 0, bottom = r, left = 0, right = c;
        //vector <int> result;
    
  while(top<bottom && left<right)
	 {
	     int i, j;
	    // i = top;
	     for(j=left;j<right;j++)
	     {
	         cout<<matrix[top][j]<<" ";
	         //result.push_back(matrix[top][j]);
	     }
	     top++;
	     //j = right;
	     
	    
	     for(i=top;i<bottom;i++)
	     {
	         cout<<matrix[i][right-1]<<" ";
	         //result.push_back(matrix[i][right-1]);
	     }
	     right--;
	     
	    // i = bottom;
	     if(top<bottom)
	     {
	        for(j = right-1;j>=left;j--)
	        {
	            cout<<matrix[bottom-1][j]<<" ";
	            //result.push_back(matrix[bottom-1][j]);
	        }
	         bottom--;
	     }
	     
	     //j = left;
	     if(left < right)
	     {
	        for(i=bottom-1;i>=top;i--)
	        {
	            cout<<matrix[i][left]<<" ";
	            //result.push_back(matrix[i][left]);
	        }
	         left++;
	     }
	     
	 }
}


int main()
{
	int matrix[M][N] =
	{
		{ 1,  2,  3,  4, 5},
		{16, 17, 18, 19, 6},
		{15, 24, 25, 20, 7},
		{14, 23, 22, 21, 8},
		{13, 12, 11, 10, 9}
	};

	printSpiral(matrix, M, N);

	return 0;
}
