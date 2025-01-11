
    /*
    Time complexity : O(n)
    Space complexity : O(1)
    */


class Solution {
public:
    bool canConstruct(string s, int k) 
    {
        // always for a character count or number of elements in array to find freq are fixed use frequency array instead of a unordered map
        if(k > s.size()) return false;
        
        int letter_count[26] = {0};

        for(char i : s)
        {
            letter_count[i -'a']++;
        }

        int odd_count = 0;
        for(int i : letter_count) if(i % 2 != 0) odd_count++;

        if(odd_count > k) return false;
        return true;
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/construct-k-palindrome-strings/
    */

    