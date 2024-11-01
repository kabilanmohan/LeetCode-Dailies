
    /*
    Time complexity : O(n*amount)
    Space complexity : O(n*amount)
    */


class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(),vector<int> (amount+1,-1));
        return func_change(coins.size()-1,amount,coins,dp);
    }

    int func_change(int idx , int amount , vector<int> &coins,vector<vector<int>> &dp)
    {
        if(idx == 0)
        {
            if((amount % coins[0]) == 0) return 1;
            return 0;
        }
        if(dp[idx][amount]!=-1) return dp[idx][amount];

        // pick case
        int pick = 0;
        if(amount >= coins[idx])
        {
            pick = func_change(idx,amount-coins[idx],coins,dp);
        }
        // not pick case
        int not_pick = 0;
        not_pick = func_change(idx-1,amount,coins,dp);

        return dp[idx][amount] = pick+not_pick;
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/coin-change-ii
    */

    