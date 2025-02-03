
    /*
    Time complexity : O(N)
    Space complexity : O(1)
    */


class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) 
    {
        int left = 0 , right , n =nums.size() , result = 1;

        for(right = 1 ; right < n ; right++)
        {
            if(nums[right] > nums[right-1]) result = max(result , right - left + 1);
            else left = right;
        }   

        left = 0;
        for(right = 1 ; right < n ; right++)
        {
            if(nums[right] < nums[right-1]) result = max(result , right - left + 1);
            else left = right;
        }  
        return result;
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/
    */

    