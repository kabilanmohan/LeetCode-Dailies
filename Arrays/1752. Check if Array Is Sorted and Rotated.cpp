
    /*
    Time complexity : O(n)
    Space complexity : O(1)
    */


class Solution {
public:
    bool check(vector<int>& nums) 
    {
        int n = nums.size();
        if(n == 1) return true;

        int shift_point = -1;
        for(int i = 0 ; i < n - 1 ; i++)
        {
            if(nums[i] > nums[i+1]) shift_point = i;
        }

        if(shift_point == -1) return true;
        if(nums[n-1] > nums[0]) return false;

        for(int i = 0 ; i < shift_point ; i++)
        {
            if(nums[i] > nums[i+1]) return false;
        }
        for(int i = shift_point + 1 ; i < n - 1 ; i++)
        {
            if(nums[i] > nums[i+1]) return false;
        }

        return true;
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/
    */

    