
    /*
    Time complexity : O(n*m)
    Space complexity : O(n*m)
    */


class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) 
    {
        int maximum = 0;
        int m = grid[0].size();
        int n = grid.size();
        vector<vector<int>> dp(n , vector<int> (m, -1));
        for(int i = 0; i < grid.size() ; i++)
        {
            maximum = max(maximum,moves(grid,i,0,n,m,dp));
        }
        return maximum;
        
    }
    int moves(vector<vector<int>>& grid, int row , int col, int m , int n,vector<vector<int>>& dp)
    {
        if(dp[row][col]!=-1) return dp[row][col];
        int direction1 = 0,direction2 = 0,direction3 = 0;
        if((row-1 >= 0) && (col+1 < n) && (grid[row][col] < grid[row-1][col+1]))
        {
            direction1 = 1 + moves(grid,row-1,col+1,m,n,dp);
        }
        if((col+1 < n) && (grid[row][col] < grid[row][col+1]))
        {
            direction2 = 1 +moves(grid,row,col+1,m,n,dp);
        }
        if((row+1 < m) && (col+1 < n) && (grid[row][col] < grid[row+1][col+1]))
        {
            direction3 = 1 + moves(grid,row+1,col+1,m,n,dp);
        }
        return dp[row][col] = max(direction1,max(direction2,direction3));
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/maximum-number-of-moves-in-a-grid/
    */

    