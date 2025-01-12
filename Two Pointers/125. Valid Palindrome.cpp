
    /*
    Time complexity : O(N)
    Space complexity : O(1)
    */


class Solution {
public:
    bool isPalindrome(string s) 
    {
        int start = 0 , end = s.size() - 1;
        
        for(int i  = 0 ; i < s.size() ; i++) s[i] = tolower(s[i]);
        while(start < end)
        {
            if(!isalnum(s[start]))
            {   
                start++;
                continue;
            }
            if(!isalnum(s[end]))
            {
                end--;
                continue;
            }
            if(s[start] != s[end]) return false;
            else
            {
                start++;
                end--;
            }
        }
        
        return true;
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/valid-palindrome/
    */

    