
    /*
    Time complexity : O(n)
    Space complexity : O(1)
    */


class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        int n = nums.size();
        int exp_sum = (n * (n+1)) / 2;

        int sum = 0;
        for(int &i:nums) sum += i;
        
        return exp_sum - sum;
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/missing-number/
    */

    