
    /*
    Time complexity : O(n^2)
    Space complexity : O(n^2)
    */

    /* Normal Recursive code runs in 6ms whereas DP runs in 58ms, the reason is that even though recursive code is O(2^n) , 
    the test cases aren't large enough to take advantage of memoization and the number of overlapping subproblems are also low.
    */

class Solution {
public:
    int minSteps(int n) {
        if(n==1) return 0;
        vector<vector<int>> dp(n+1 , vector<int> (n+1,-1));
        return func_steps(1,1,n,dp);
    }

    int func_steps(int length , int a_clip , int n , vector<vector<int>> &dp)
    {
        if(length == n) return 1;
        
        if(dp[length][a_clip] != -1) return dp[length][a_clip];

        // paste case
        int paste = 1e9;
        if((length + a_clip) <= n)
        {
            paste = 1 + func_steps(length + a_clip , a_clip , n , dp);
        }

        //copy_paste case
        int copy_paste = 1e9;
        if((2 * length) <= n)
        {
            copy_paste = 2 + func_steps(2 * length , length , n , dp);
        }

        return dp[length][a_clip] = min(paste,copy_paste);
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/2-keys-keyboard/
    */

    
