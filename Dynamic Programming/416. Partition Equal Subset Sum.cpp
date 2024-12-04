
    /*
    Time complexity : O(n*sum)
    Space complexity : O(n*sum)
    */


class Solution {
public:
    bool canPartition(vector<int>& nums) 
    {
        int sum = 0;
        for(auto i:nums) sum+=i;
        if(sum%2 != 0) 
        {
            return false;
        }

        vector<vector<int>> dp(nums.size()+1 , vector<int> (sum + 1 , -1));
        return subsetsum(0 , nums , sum/2 , dp);
    }

    bool subsetsum(int idx , vector<int> &nums , int sum , vector<vector<int>> &dp)
    {
        if(sum == 0) return true;
        if(sum < 0 || idx == nums.size()) return false;

        if(dp[idx][sum] != -1) return dp[idx][sum];

        bool pick = false , nopick = false;
        
        // pick
        pick = subsetsum(idx+1 , nums , sum-nums[idx] , dp);

        //no pick
        nopick = subsetsum(idx+1 , nums , sum , dp);

        return dp[idx][sum] = pick || nopick;
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/partition-equal-subset-sum/
    */

    