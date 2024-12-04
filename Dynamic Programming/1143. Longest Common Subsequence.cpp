
    /*
    Time complexity : O(m*n)
    Space complexity : O(m*n)
    */


class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size() + 1 , vector<int> (text2.size() + 1 ,-1));         
        return LCS(0,0,text1,text2 , dp);  
    }
    
    int LCS(int idx1 , int idx2 , string &text1 , string &text2 , 
    vector<vector<int>> &dp)
    {
        if(idx1 == text1.size() || idx2 == text2.size()) return dp[idx1][idx2] = 0;

        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];

        // match
        int match = -1e9;
        int no_match1 = -1e9;
        int no_match2 = -1e9;
        if(text1[idx1] == text2[idx2])
        {
            match = 1 + LCS(idx1 + 1 , idx2 + 1 , text1 , text2 , dp);
        }
        else
        {
            // no match
            no_match1 = LCS(idx1 + 1 , idx2 , text1 , text2 , dp);
            no_match2 = LCS(idx1 , idx2 + 1 , text1 , text2 , dp);
        }
        

        return dp[idx1][idx2] = max({match , no_match1 , no_match2});
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/longest-common-subsequence/
    */

    