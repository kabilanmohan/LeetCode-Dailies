
    /*
    Time complexity : O(n)
    Space complexity : O(1)
    */


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum = -1e9;
        int sum = 0;
        for(int i:nums)
        {
            sum+=i;
            maxsum = max(maxsum , sum);
            if(sum < 0) sum = 0;
        }
        return maxsum;
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/maximum-subarray/description/
    */

    