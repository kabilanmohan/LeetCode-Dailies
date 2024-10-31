
    /*
    Time complexity : O(m*n)
    Space complexity : O(m*n)
    */


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return func_paths(grid,m-1,n-1,dp);
    }

    int func_paths(vector<vector<int>>& grid, int m, int n,vector<vector<int>> &dp)
    {
        if(m==0 && n==0) return grid[0][0];
        if(m<0 || n<0) return 1e9;
        if(dp[m][n]!= -1) return dp[m][n];
        return dp[m][n] = min(grid[m][n] + func_paths(grid,m-1,n,dp) ,
        grid[m][n] + func_paths(grid,m,n-1,dp));
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/minimum-path-sum/
    */

    