#include <iostream>
using namespace std;
//#define N 4
const int m=3, n=3;

void printAllDgl(int matrix[m][n])  // m = rows, n=cols
 {
     int k,j,i;
    for(k=0;k<m;k++)
    {
        i = k, j=0;
        while(i>=0)
        {
            cout<< matrix[i][j]<<" ";
            i=i-1;
            j=j+1;
        }
    }
    
    for(k=1;k<n;k++)
    {
        i = m-1;
        j=k;
        while(j<=n-1)
        {
            cout<<matrix[i][j]<<" ";
            i=i-1;
            j=j+1;
        }
    }
}



int main(void){
  
    int matrix[][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
  
  /// output: 1 4 2 7 5 3 8 6 9 
    printAllDgl(matrix);
  return 0;
}
