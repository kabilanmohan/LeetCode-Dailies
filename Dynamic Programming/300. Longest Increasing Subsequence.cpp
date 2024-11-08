
    /*
    Time complexity : O(N^2)
    Space complexity : O(N^2)
    */


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return LIS(0, -1, nums, dp);
    }

    int LIS(int idx, int lastpick_idx, vector<int>& nums, vector<vector<int>>& dp) {
        if (idx == nums.size()) return 0;

        if (dp[idx][lastpick_idx + 1] != -1) return dp[idx][lastpick_idx + 1];

        // pick case
        int pick = 0;
        if (lastpick_idx == -1 || nums[idx] > nums[lastpick_idx]) {
            pick = 1 + LIS(idx + 1, idx, nums, dp);
        }

        // not pick case
        int not_pick = LIS(idx + 1, lastpick_idx, nums, dp);

        return dp[idx][lastpick_idx + 1] = max(pick, not_pick);
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/longest-increasing-subsequence/
    */

    