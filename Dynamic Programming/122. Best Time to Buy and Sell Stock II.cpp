
    /*
    Time complexity : O(n)
    Space complexity : O(n)
    */


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int> (2,-1));
        return func_profit(0,1,prices,dp);
    }

    int func_profit(int idx , int can_buy , vector<int>& prices,
    vector<vector<int>>& dp)
    {
        if(idx == prices.size()) return 0;
        if (dp[idx][can_buy]!=-1) return dp[idx][can_buy];
        int buy = -1e9,not_buy = -1e9,sell = -1e9,not_sell = -1e9;
        if(can_buy)
        {
            //buy case
            buy = func_profit(idx+1,0,prices,dp) - prices[idx];
            //not buy case
            not_buy = func_profit(idx+1,1,prices,dp);
        }
        else
        {
            //sell case
            sell = func_profit(idx+1,1,prices,dp) + prices[idx];
            //not sell case
            not_sell = func_profit(idx+1,0,prices,dp);
        } 
        return dp[idx][can_buy] = max(buy,max(not_buy,max(sell,not_sell)));
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
    */

    