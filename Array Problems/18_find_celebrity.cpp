#include <bits/stdc++.h> 
using namespace std; 

int celebrity(vector<vector<int> >& M, int n) 
    {
        int x=0, y=n-1;
        while(x<y)
        {
            if(M[x][y]==1)
            {
                x++;
             }
            else
            {
                 y--;
            }
        }
  
       int per_know_cel = 0, cel_know_per=0;
        for(int i=0;i<n;i++)
        {
            if(i!=x)
            {
                if(M[i][x])
                {
                    per_know_cel++;
                }
                
                if( M[x][i]==1)
                {
                    cel_know_per++;
                }
             }
        }
    
        if(per_know_cel<n-1 || cel_know_per>0)
        {
            return -1;
        }
    return x;
    }


int main() 
{ 
  vector <vector<int>> matrix = {{0, 1, 0}, 
                                 {0, 0, 0}, 
                                 {0, 1, 0}}; 
   
    int n = matrix.size(); 
  
    int id = findCelebrity(matrix, n); 
    id == -1 ? cout << "No celebrity Found" : 
               cout << "Celebrity ID is " 
                    << id; 
    return 0; 
} 


/* Try more Inputs
case 1: 
static int matrix[][] = {{0, 1, 0}, 
                         {0, 0, 0}, 
                         {0, 1, 0}};
expected = 1

case2: 
static int matrix[][] = {{0, 1},
                        {1, 0}};
 expected = -1
 
Note: The two people at party know each other. None of them is a celebrity
 
case 3: 
static int matrix[][] = { {0, 0, 1, 0},
                            {0, 0, 1, 0},
                         {0, 1, 0, 0},
                         {0, 0, 1, 0} };
expected = -1
*/
