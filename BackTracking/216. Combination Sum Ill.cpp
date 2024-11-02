
    /*
    Time complexity : O(2^9)
    Space complexity : O(number of valid combinations * k)
    */


class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> result;
        vector<vector<int>> ans;
        func_combi(1,k,n,result,ans);
        return ans;

    }

    void func_combi(int number ,int k , int n , vector<int> &result , 
    vector<vector<int>> &ans)
    {
        if(result.size() == k)
        {
            if(n == 0) ans.push_back(result);
            return;
        }

        //pick
        if(number <= 9 && (n - number) >=0)
        {
            result.push_back(number);
            func_combi(number+1 , k , n-number , result , ans);
            result.pop_back();
        }
        //not pick
        if(number <= 9 && (n - number) >=0)
        {
            func_combi(number+1 , k , n , result , ans);
        }
        return;
    }
    
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/combination-sum-iii/
    */

    