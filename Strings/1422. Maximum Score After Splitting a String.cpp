
    /*
    Time complexity : O(n)
    Space complexity : O(1)
    */


class Solution {
public:
    // prefix sum approach but O(n) space
    int maxScore(string s) 
    {
        int n = s.size();
        vector<int> zero(n,0) , one(n,0);
        int count = 0;
        for(int i = 0 ; i < n ; i++)
        {
            if(s[i] == '0') count++;
            zero[i] = count;
        }

        count = 0;
        for(int i = n - 1 ; i >= 0 ; i--)
        {
            if(s[i] == '1') count++;
            one[i] = count;
        }

        int max = 0;
        for(int i = 0 ; i < n - 1 ; i++)
        {
            if((zero[i]+one[i+1]) > max) max = zero[i] + one [i+1];
        }
        return max;
    }

    // Optimal O(1) space
    int maxScore(string s)
    {
        int result = 0;
        int zeroes_to_left = 0;
        int ones_to_right = count(s.begin() , s.end() , '1');

        for(int i = 0 ; i < s.size() - 1 ; i++)
        {
            if(s[i] == '0') zeroes_to_left++;
            if(s[i] == '1') ones_to_right--;
            result = max(result , zeroes_to_left + ones_to_right);
        }
        return result;
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/maximum-score-after-splitting-a-string/
    */

    