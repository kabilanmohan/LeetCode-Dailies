
    /*
    Time complexity : O(n*m)
    Space complexity : O(n*m)
    */


class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size()+1 , vector<int> (p.size() + 1 , -1));
        return regular(s.size() - 1 , p.size() - 1 , s, p ,dp);
    }

    int regular(int idx1 , int idx2 , string &s , string &p ,vector<vector<int>> &dp)
    {
        //base cases
        if(idx1 < 0  && idx2 < 0 ) return 1; // both reached start
        if(idx1 < 0) //if s reached start , alternate remaining char in p must be *
        {
            for(int i = idx2 ; i >=0 ; i = i - 2)
            {
                if(p[i] != '*') return 0;
            }
            return 1;
        }
        if(idx2 < 0) return 0; //p reached start but s didnt
        

        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
        
        int match = 0 , ques = 0 , star1 = 0 , star2 = 0;

        // both char match
        if(s[idx1] == p[idx2]) match = regular(idx1 - 1 , idx2 - 1 , s, p ,dp);

        // . condition
        if(p[idx2] == '.') ques = regular(idx1 - 1 , idx2 - 1 , s, p ,dp);

        // * condition
        if(p[idx2] == '*')
        {
            //replacing * with n number of characters
            if(idx1 >= 0 && ( s[idx1] == p[idx2 - 1] || p[idx2 - 1] == '.') )
            {
                star1 = regular(idx1 - 1 ,idx2, s, p ,dp);
            }  
            //jumping 2 index (replacing * as empty )
            star2 = regular(idx1, idx2 - 2, s, p ,dp);
            
        } 

        return dp[idx1][idx2] = (match || ques || star1 || star2) ;

    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/regular-expression-matching/
    */

    