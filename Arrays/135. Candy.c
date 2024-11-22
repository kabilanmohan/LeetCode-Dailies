/*

  Time Complexity : O(n)
  Space Complexity : O(1)

*/

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies (n,1);

        for(int i = 1 ; i < n ; i ++)
        {
            if(ratings[i] > ratings[i-1]) candies[i] = candies[i-1] + 1;
        }

        int sum = 0;
        for(int i = n - 2 ; i >= 0 ; i --)
        {
            sum += candies[i+1];
            if(ratings[i] > ratings[i+1]) 
            {
                if(candies[i] > candies[i+1]) continue;
                candies[i] = candies[i+1] + 1;
            }
    
        }
        sum += candies[0];

        return sum;
    }
};

/*
  Question Link : https://leetcode.com/problems/candy/
  Author : kabilanmohan
*/


