
    /*
    Time complexity : O(n*n!)
    Space complexity : O(n)
    */


class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> result;
        set<vector<int>> ans;
        func_permute(nums,result,ans);
        return vector<vector<int>> (ans.begin(),ans.end());
    }

    void func_permute(vector<int>& nums , vector<int> &result, set<vector<int>> &ans)
    {
        if(result.size() == nums.size())
        {
            ans.insert(result);
            return;
        }

        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(nums[i] == -1e9) continue;

            // assigning -1e9 to show that index has already been taken
            else result.push_back(nums[i]);
            nums[i] = -1e9;

            //recursive call
            func_permute(nums,result,ans);

            //backtracking step, reassigning the value of that index to original value
            nums[i] = result[result.size()-1];
            result.pop_back();
        }
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/permutations-ii/
    */

    
