
    /*
    Time complexity : O(N)
    Space complexity : O(N)
    */


class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int left = 0; // window starting point
        int result = 0;

        unordered_map<char,int> substr; // storing last occurence of each char

        for(int i = 0 ; i < s.size() ; i++)
        {
            // char not in map
            if(!substr.count(s[i]))
            {
                substr[s[i]] = i;
            }
            else
            {
                // move start of window to the point of last occurence of current char + 1 only if that last occurence is greater than left
                if(substr[s[i]] >= left) left = substr[s[i]] + 1; 
                // update the last occurence
                substr[s[i]] = i;
            }
            result = max(result , i - left + 1);
        }
        return result;
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/longest-substring-without-repeating-characters
    */

    