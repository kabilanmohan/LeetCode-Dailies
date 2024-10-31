
    /*
    Time complexity : O(n*m)
    Space complexity : O(n*m)
    */


class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        vector<vector<int>> dp(triangle.size(),
        vector<int>(triangle[triangle.size()-1].size(),-1));
        
        return func_triangle(triangle,0,0,dp);
    }
    int func_triangle(vector<vector<int>>& triangle, int row, int col,
    vector<vector<int>> &dp)
    {
        if(row == triangle.size()-1) return triangle[row][col];
        if(dp[row][col] != -1) return dp[row][col];

        int left = triangle[row][col] + func_triangle(triangle , row+1,col,dp);
        int right = triangle[row][col] + func_triangle(triangle , row+1,col+1,dp);

        return dp[row][col] = min(left,right);
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/triangle/
    */

    