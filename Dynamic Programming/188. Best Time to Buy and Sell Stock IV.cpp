
    /*
    Time complexity : O(n*k)
    Space complexity : O(n*k)
    */


class Solution {
public:
    int maxProfit(int k , vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(),
         vector<vector<int>>(2, vector<int>(2*k + 1, -1)));
        return func_profit(k,0,1,0,prices,dp);
    }

    int func_profit(int k ,int idx , int can_buy , int transactions , vector<int>& prices,
    vector<vector<vector<int>>>& dp)
    {
        if(idx == prices.size() || transactions > 2*k) return 0;
        if (dp[idx][can_buy][transactions]!=-1) return dp[idx][can_buy][transactions];
        int buy = -1e9,not_buy = -1e9,sell = -1e9,not_sell = -1e9;
        if(can_buy)
        {
            //buy case
            buy = func_profit(k,idx+1,0,transactions+1,prices,dp) - prices[idx];
            //not buy case
            not_buy = func_profit(k,idx+1,1,transactions,prices,dp);
        }
        else
        {
            //sell case
            sell = func_profit(k,idx+1,1,transactions+1,prices,dp) + prices[idx];
            //not sell case
            not_sell = func_profit(k,idx+1,0,transactions,prices,dp);
        } 
        return dp[idx][can_buy][transactions] = max(buy,max(not_buy,max(sell,not_sell)));
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
    */

    