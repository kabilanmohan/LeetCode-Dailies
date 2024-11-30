
    /*
    Time complexity : O(N)
    Space complexity : O(N)
    */


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> prefix;
        int sum = 0;
        prefix[0] = 1;
        int result = 0;

        for(int i = 0 ; i < nums.size() ; i++)
        {
            sum += nums[i];
            
            if(prefix.count(sum-k)) result += prefix[sum-k];
            
            if(!prefix.count(sum)) prefix[sum] = 1;
            else prefix[sum] += 1;
        }

        return result;

    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/subarray-sum-equals-k/
    */

    