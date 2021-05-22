#include <bits/stdc++.h> 
using namespace std; 
  
#define N 4 
// Give any value of N
// Function to rotate the matrix 90 degree clockwise 

// We can define a vector instead of matrix.
void matrixRotation(int matrix[N][N]) 
{ 
   int n = N;
   for(int i=0;i<n/2;i++)
   {
       for(int j=i;j<n-i-1;j++)
       {
           int temp = matrix[j][n-1-i];
           matrix[j][n-1-i] = matrix[i][j];
           matrix[i][j] = matrix[n-1-j][i];
           matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
           matrix[n-1-i][n-1-j] = temp;
           
       }
   }
} 
  

void printMatrix(int matrix[N][N]) 
{ 
    for (int i = 0; i < N; i++) { 
        for (int j = 0; j < N; j++) 
            cout << matrix[i][j] << " "; 
        cout << '\n'; 
    } 
} 
  

int main() 
{ 
    int matrix[N][N] = { { 1, 2, 3, 4 }, 
                      { 5, 6, 7, 8 }, 
                      { 9, 10, 11, 12 }, 
                      { 13, 14, 15, 16 } }; 
    matrixRotation(matrix); 
    printMatrix(matrix); 
    return 0; 
} 

/* Try more Inputs
case 1: 
int matrix[][] = { { 1, 2, 3}, 
                   { 4, 5, 6}, 
                   { 7, 8, 9}}; 

actual = matrixRotation(matrix)
expected = 7  4  1 
           8  5  2 
           9  6  3
*/
