#include <bits/stdc++.h>
using namespace std;

// We are NOT considering diagonally connected elements

void mark_island(vector<vector<char>>& grid, int x, int y, int r, int c)
    {
        if(x<0 || x>=r || y<0 || y>=c || grid[x][y]!='1')
        {
            return;
        }
        grid[x][y] = '2';
        
        mark_island(grid, x+1, y, r, c);
        mark_island(grid, x, y+1, r, c);
        mark_island(grid, x-1, y, r, c);
        mark_island(grid, x, y-1, r, c);
    }
    
    
    int numIslands(vector<vector<char>>& grid) {
        
        int rows = grid.size();
        if(rows==0)
        {
            return 0;
        }
        int col = grid[0].size();
        int num_islands = 0;
        
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]=='1')
                {
                    mark_island(grid, i, j, rows, col);
                    num_islands+=1;
                }
            }
        }
        
        return num_islands;
    }


int main()
{
    vector<vector<int>> boolmat = { {"1","1","1","1","0"},
                                    {"1","1","0","1","0"},
                                    {"1","1","0","0","0"},
                                    {"0","0","0","0","0"}
                                  } /// answer = 1
}
