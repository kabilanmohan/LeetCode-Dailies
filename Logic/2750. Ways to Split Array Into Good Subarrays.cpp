
    /*
    Time complexity : O(n)
    Space complexity : o(1)
    */


class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) 
    {
        // count number of zeroes between 2 ones
        int mod = 1e9 + 7;
        long long result = 0;
        int i = 0;

        while(i < nums.size() && nums[i] == 0) i++; // skip leading zeroes

        while(i < nums.size())
        {
            if(nums[i] == 0) 
            {
                i++;
                continue;
            }

            int zero_count = 0;
            i++;

            while(i < nums.size() && nums[i] == 0)
            {
                zero_count++;
                i++;
            }

            if(result == 0) result = 1;
            if(i >= nums.size() || zero_count == 0) continue;
            
            result *= (zero_count+1);
            result %= mod;

        }
        return result;
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/ways-to-split-array-into-good-subarrays/
    */

    