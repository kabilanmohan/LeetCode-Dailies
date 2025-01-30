
    /*
    Time complexity : O(M*N)
    Space complexity : O(M+N) -> recursive stack space
    */


class Solution {
public:

    int dfs(int row , int col , vector<vector<int>> &grid)
    {
        if(row >= grid.size() || row < 0 || col >= grid[0].size() || col < 0) return 0;
        if(grid[row][col] == 0) return 0;

        int left = 0  , right = 0 , up = 0 , down = 0;

        grid[row][col] = 0;

        left = dfs(row , col + 1 , grid);
        right = dfs(row, col - 1, grid);
        down = dfs(row + 1 , col , grid);
        up = dfs(row - 1 , col , grid);

        return 1 + left + right + down + up;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        int result = 0 , rows = grid.size() , cols = grid[0].size();

        for(int i = 0 ; i < rows ; i++)
        {
            for(int j = 0 ; j < cols ; j++)
            {
                result = max(result , dfs(i , j , grid));
            }
        }

        return result;
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/max-area-of-island/
    */

    