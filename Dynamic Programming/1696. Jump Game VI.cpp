
    /*
    Time complexity : O(n*k)
    Space complexity : O(n)
    */

    /* The solution gave TLE for larger values of K. The naive DP approach given above isnt the solution 
        as original solution needs to include DP with Priority Queue. Hence to be solved later.
    */
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        vector<int> dp(nums.size() , -1);
        return func_result(0 , nums , k , dp);
    }

    int func_result(int idx , vector<int>& nums, int k , vector<int>& dp)
    {
        if(idx == nums.size()-1) return nums[idx];

        if(dp[idx] != -1) return dp[idx];
        int max_sum = -1e9;

        for(int i = 1 ; i <= k  && idx+i < nums.size(); i++)
        {
            max_sum = max(max_sum , (nums[idx] + func_result(idx + i , nums , k , dp)));
        }

        return dp[idx] = max_sum;
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/jump-game-vi/
    */

    
