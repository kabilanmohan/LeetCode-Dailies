
    /*
    Time complexity : O(n*m)
    Space complexity : O(n*m0
    */


class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size()+1 , vector<int> (p.size()+1 , -1));
        return wildcard(0 , 0 , s, p ,dp);
    }

    int wildcard(int idx1 , int idx2 , string &s , string &p ,vector<vector<int>> &dp)
    {
        //base cases

        //both reached end --> true case
        if(idx1 == s.size() && idx2 == p.size()) return dp[idx1][idx2] = 1;
        // if s reaches end the remaining char in p must be *
        if(idx1 == s.size())
        {
            for(int i = idx2; i < p.size() ; i++)
            {
                if(p[i] != '*') return dp[idx1][idx2] = 0; // false case
            }
            return 1; // true case
        }
        //p reached end but s didnt --> false case
        if(idx2 == p.size()) return dp[idx1][idx2] = 0;

        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
        
        int match = 0 , ques = 0 , star1 = 0 , star2 = 0;

        // both char match
        if(s[idx1] == p[idx2]) match = wildcard(idx1 + 1 , idx2 + 1 , s, p ,dp);

        // ? condition
        if(p[idx2] == '?') ques = wildcard(idx1 + 1 , idx2 + 1 , s, p ,dp);

        // * condition
        if(p[idx2] == '*')
        {
            star1 = wildcard(idx1 + 1, idx2, s, p ,dp);
            star2 = wildcard(idx1, idx2 + 1, s, p ,dp);
            
        } 

        return dp[idx1][idx2] = (match || ques || star1 || star2) ;

    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/wildcard-matching/
    */

    