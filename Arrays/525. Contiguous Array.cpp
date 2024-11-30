
    /*
    Time complexity : O(N)
    Space complexity : O(N)
    */


class Solution {
public:
    int findMaxLength(vector<int>& nums) 
    {
        // storing first occurence of that prefix sum
        unordered_map<int,int> prefix;

        int sum = 0;
        int result = 0;
        prefix[0] = -1;

        for(int i = 0 ; i < nums.size() ; i++)
        {

            if(nums[i] == 0) sum--;
            else sum++;

            if(prefix.count(sum)) result = max(result ,  i - prefix[sum]);

            if(!prefix.count(sum)) prefix[sum] = i;
            
        }
        return result;
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/contiguous-array/
    */

    