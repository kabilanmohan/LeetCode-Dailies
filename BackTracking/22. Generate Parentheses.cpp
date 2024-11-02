
    /*
    Time complexity : O(4^n / n^(3/2)) - nth catalan number
    Space complexity : O(4^n / n^(1/2))
    */


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string result = "";
        func_paran(n , 0 , 0 , result , ans);
        return ans;
    }

    void func_paran(int n , int open , int close , string &result ,
     vector<string> & ans)
    {
        if(result.size() == 2*n)
        {
            if((open - close) == 0)ans.push_back(result);
            return;
        }

        // push (
        if(open + 1 <= n)
        {
            result += '(';
            func_paran(n , open + 1 , close , result , ans);
            result.pop_back();
        }
        // push )
        if(open > close)
        {
            result += ')';
            func_paran(n , open , close + 1 , result , ans);
            result.pop_back();

        }
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/generate-parentheses/
    */

    