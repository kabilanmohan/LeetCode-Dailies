
    /*
    Time complexity : O(2^n)
    Space complexity : O(2^n)
    */


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> result;
        func_subset(0,nums,ans,result);
        return ans;
    }

    void func_subset(int idx , vector<int>& nums , vector<vector<int>> &ans , 
    vector<int> &result)
    {
        if(idx == nums.size())
        {
            ans.push_back(result);
            return;
        }
        // pick condition
        result.push_back(nums[idx]);
        func_subset(idx+1,nums,ans,result);
        result.pop_back();

        //not pick condition
        func_subset(idx+1,nums,ans,result);
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/subsets/
    */

    