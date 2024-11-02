
    /*
    Time complexity : O(k * C(n,k))
    Space complexity : O(k * C(n,k))
    */


class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> result;
        func_combinations(1,n,k,ans,result);
        return ans;
    }

    void func_combinations(int number , int n , int k , vector<vector<int>> &ans ,
     vector<int> &result)
     {
        if(result.size() == k)
        {
            ans.push_back(result);
            return;
        }
        if(number <= n )
        {
            // pick condition
            result.push_back(number);
            func_combinations(number+1,n,k,ans,result);
            result.pop_back();

            // not pick condition
            func_combinations(number+1,n,k,ans,result);
        }
        return;
     }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/combinations/?envType=study-plan-v2&envId=top-interview-150
    */

    