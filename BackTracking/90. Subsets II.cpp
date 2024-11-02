
    /*
    Time complexity : Not Defined
    Space complexity : O(2^n)
    */


class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int> result;
        sort(nums.begin(),nums.end());
        func_subset(0,nums,ans,result);
        return vector<vector<int>> (ans.begin(),ans.end());
    }

    void func_subset(int idx , vector<int>& nums , set<vector<int>> &ans , 
    vector<int> &result)
    {
        if(idx == nums.size())
        {
            ans.insert(result);
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
    Question Link : https://leetcode.com/problems/subsets-ii/
    */

    