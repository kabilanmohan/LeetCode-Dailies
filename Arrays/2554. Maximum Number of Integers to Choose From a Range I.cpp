
    /*
    Time complexity : O(n)
    Space complexity : O(n)
    */


class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) 
    {
        unordered_set<int> ban(banned.begin() , banned.end());

        int count = 0;
        int sum = 0;
        for(int i = 1 ; i <= n ; i++)
        {
            if(!ban.count(i))
            {
                sum += i;
                count++;
                if(sum > maxSum) return --count;
            }
        }
        return count;

    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i/
    */

    