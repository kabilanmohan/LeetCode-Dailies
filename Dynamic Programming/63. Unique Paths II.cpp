
    /*
    Time complexity : O(m*n)
    Space complexity : O(m*n)
    */


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return func_paths(obstacleGrid,m-1,n-1,dp);
    }

    int func_paths(vector<vector<int>>& obstacleGrid ,int m, int n,
    vector<vector<int>> &dp)
    {
        if(m==0 && n==0 && obstacleGrid[m][n] == 0) return 1;
        if(m<0 || n<0 || obstacleGrid[m][n] == 1) return 0;

        if(dp[m][n]!= -1) return dp[m][n];


        return dp[m][n] = func_paths(obstacleGrid,m-1,n,dp) + 
        func_paths(obstacleGrid,m,n-1,dp);
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/unique-paths-ii/
    */

    