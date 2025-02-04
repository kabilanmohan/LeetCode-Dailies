
    /*
    Time complexity : O(N)
    Space complexity : O(1)
    */


class Solution {
public:
    int maxAscendingSum(vector<int>& nums) 
    {
        int currSum = nums[0] , maxSum = nums[0], n = nums.size();
        for(int i = 1 ; i < n ; i++)
        {
            if(nums[i - 1] >= nums[i]) currSum = nums[i];
            else currSum += nums[i];

            maxSum = max(maxSum , currSum);
        }
        return maxSum;
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/maximum-ascending-subarray-sum
    */

    