#include <bits/stdc++.h>


// TO mark and count the number of 1s in the connected island
int count_region_cells(vector<vector<int>>& grid, int r, int c)
    {
        if(r<0 || r>=grid.size() || c<0 || c>= grid[0].size() || grid[r][c]==0)
        {
            return 0;
        }
        
        int cell_count = 1;
        grid[r][c]= 0;
        
        for(int i=r-1;i<=r+1;i++)
        {
            for(int j=c-1; j<=c+1; j++)
            {
                if(i==r && j==c);
                else
                {
                    cell_count+=count_region_cells(grid, i, j);
                }
            }
        }
        
        return cell_count;
    }

// returns the size of the biggest island    
int findMaxArea(vector<vector<int>>& grid) {
        int max_cell_size=0;
        int row = grid.size(), col = grid[0].size();
        if(row==0)
        {
            return 0;
        }
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                int count_cell = count_region_cells(grid, i, j);
                max_cell_size = max(count_cell, max_cell_size);
            }
        }
        
        return max_cell_size;
    }


int main()
{
  vector <vector<int>> matrix = {{1,1,1,0},
                                 {0,0,1,0},
                                 {0,0,0,1}} // answer = 5
}
