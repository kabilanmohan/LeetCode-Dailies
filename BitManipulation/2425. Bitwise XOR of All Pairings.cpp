
    /*
    Time complexity : O(N+M)
    Space complexity : O(1)
    */


class Solution {
public:
    //O(n^2) brute force -> TLE
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) 
    {
        int result = 0;
        for(int i:nums1)
        {
            for(int j:nums2)
            {
                result ^= (i^j);
            }
        }
        return result;
    }

    // every number in nums1 repeats nums2.size times and vice versa
    // so if it repeats even number of times , the xor result is zero and we can skip it
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) 
    {
        int result = 0;
        int n1 = nums1.size() , n2 = nums2.size();

        if(n2 %2 != 0)
        {
            for(int i : nums1) result ^= i;
        }

        if(n1 %2 != 0)
        {
            for(int i : nums2) result ^= i;
        }
        return result;
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/bitwise-xor-of-all-pairings/
    */

    