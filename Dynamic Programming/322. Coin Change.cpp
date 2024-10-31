
    /*
    Time complexity : O(n*Amount)
    Space complexity : O(n*Amount)
    */


class Solution {
public:
    int f(int i,int sum,vector<int>& coins,vector<vector<int>> &dp)
    {
        if(i == 0)
        {
            if(sum%coins[0] == 0) return sum/coins[0];
            return 1e9;
        }
        
        if(dp[i][sum]!= -1) return dp[i][sum];

        int notpick = 0 + f(i-1,sum,coins,dp);
        int pick = 1e9;
        if(coins[i] <= sum)
        {
            pick = 1 + f(i,sum-coins[i],coins,dp);
        }

        return dp[i][sum] =  min(notpick,pick);
    }
    int coinChange(vector<int>& coins, int amount) {

        vector<vector<int>> dp(coins.size(),vector<int> (amount+1,-1));

        int k = f(coins.size()-1,amount,coins,dp);
        if(k>=1e9) return -1;
        return k;
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/coin-change/
    */

    