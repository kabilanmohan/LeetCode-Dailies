
    /*
    Time complexity : O(n*k)
    Space complexity : O(n)
    */


class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return func_jump(nums,0,dp);
    }
    

    int func_jump(vector<int>& nums , int idx, vector<int> &dp)
    {
        if(idx == nums.size()-1) return 0;
        if(idx > nums.size()-1) return 1e9;
        if(dp[idx]!= -1) return dp[idx];
        int steps = 1e9;
        for(int i = 1;i<=nums[idx];i++)
        {
            steps = min(steps,1+func_jump(nums,idx+i,dp));
        }
        return dp[idx] = steps;
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/jump-game-ii/description/
    */

    