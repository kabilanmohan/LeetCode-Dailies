
    /*
    Time complexity : O(m*n)
    Space complexity : O(m*n)
    */


class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return func_paths(m-1,n-1,dp);
    }

    int func_paths(int m, int n,vector<vector<int>> &dp)
    {
        if(m==0 && n==0) return 1;
        if(m<0 || n<0) return 0;
        if(dp[m][n]!= -1) return dp[m][n];
        return dp[m][n] = func_paths(m-1,n,dp) + func_paths(m,n-1,dp);
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/unique-paths/
    */

    