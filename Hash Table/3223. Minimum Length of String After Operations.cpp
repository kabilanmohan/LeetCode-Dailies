
    /*
    Time complexity : O(N)
    Space complexity : O(1)
    */


class Solution {
public:
    int minimumLength(string s) 
    {
        int freq[26] = {0};
        for(char i : s)
        {
            freq[i - 'a']++;
        }

        int result = 0;
        for(int i : freq)
        {
            if(i == 0) continue;
            if(i % 2 == 0) result += 2;
            else result += 1;
        }
        return result;
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/minimum-length-of-string-after-operations
    */

    