
    /*
    Time complexity : O(n*m)
    Space complexity : O(n*m)
    */


class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size() , vector<int>(word2.size(), - 1));
        return editdis(word1.size() - 1 , word2.size() - 1 , word1 , word2 , dp);
    }
    
    int editdis(int idx1 , int idx2, string &word1, string &word2 , vector<vector<int>> &dp)
    {
        //base case
        if(idx1 < 0 && idx2 < 0) return 0;
        if(idx1 < 0) return idx2 + 1;
        if(idx2 <  0) return idx1 + 1;

        if(dp[idx1][idx2] != -1 ) return dp[idx1][idx2];

        //if letters match
        if(word1[idx1] == word2[idx2]) return dp[idx1][idx2] = editdis(idx1 - 1, idx2 - 1 , word1, word2 ,dp);

        int del = 1 + editdis(idx1 - 1, idx2 , word1, word2 ,dp);

        int ins = 1 + editdis(idx1 , idx2 - 1 , word1, word2 ,dp);

        int rep = 1 + editdis(idx1 - 1, idx2 - 1 , word1, word2 ,dp);

        return dp[idx1][idx2] = min({del,ins,rep});

    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/edit-distance/
    */

    