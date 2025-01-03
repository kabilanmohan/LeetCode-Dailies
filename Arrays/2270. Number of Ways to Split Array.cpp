
    /*
    Time complexity : O(n)
    Space complexity : O(1)
    */


class Solution {
public:
    int waysToSplitArray(vector<int>& nums) 
    {
        long long total_sum = 0;
        int n = nums.size() , result = 0;

        for(int i : nums) total_sum += i;
        
        long long curr_sum = 0 ;
        for(int i = 0 ; i < n - 1 ; i++)
        {
            curr_sum += nums[i];
            if(curr_sum >= (total_sum - curr_sum)) result++;
        }
        return result;
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/number-of-ways-to-split-array
    */

    