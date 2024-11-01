
/*  Time Complexity : O(2^n) 
    Space Complexity : O(n) */



class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> solution;
        vector<vector<int>> ans;
        func_combi(0,target,candidates,solution,ans);
        return ans;
    }


    void func_combi(int idx,int target,vector<int>& candidates,
    vector<int>& solution,vector<vector<int>>& ans)
    {
        if(idx == candidates.size() || target < 0)
        {
            if(target == 0) ans.push_back(solution);
            return;
        }

        //not pick
        func_combi(idx+1,target,candidates,solution,ans);

        // pick condition
        solution.push_back(candidates[idx]);
        func_combi(idx,target-candidates[idx],candidates,solution,ans);
        solution.pop_back();

        
    }

    
};


/*  Author : kabilanmohan
    LeetCode Question Link : https://leetcode.com/problems/combination-sum/
    
*/