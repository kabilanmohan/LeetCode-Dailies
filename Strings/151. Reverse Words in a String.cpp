
    /*
    Time complexity : O(n)
    Space complexity : O(n)
    */


class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int left = n - 1;
        string result = "";
        
        while(left >=0)
        {
            int count = 0;
            while(left>= 0 && s[left]!= ' ') 
            {
                count++;
                left--;
            }
            if((left + 1) < n && s[left+1] != ' ')
            {
                result += s.substr(left + 1 , count);
                result += ' ';
            }
            left --;
        }

        return result.substr(0 , result.size()-1);
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/reverse-words-in-a-string
    */

    