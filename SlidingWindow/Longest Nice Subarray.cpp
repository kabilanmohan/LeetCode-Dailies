
    /*
    Time complexity : O(N)
    Space complexity : O(1)
    */


class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) 
    {
        int and_value = 0, left = 0 , n = nums.size();
        int result = -1e9;

        for(int right = 0 ; right < n ; right++)
        {
            // shrink and then expand (something thats different than generic sliding)

            while((nums[right] & and_value) != 0)
            {
                and_value &= (~nums[left]);
                left++;
            }

            and_value |= nums[right];
            result = max(result , right - left + 1);
        }
        return result;
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/longest-nice-subarray/
    */

    