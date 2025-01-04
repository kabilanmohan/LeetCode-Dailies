
    /*
    Time complexity : O(n)
    Space complexity : O(26) -> O(1)
    */


class Solution {
public:
    int countPalindromicSubsequence(string s) 
    {
        //maintain a map for all characters first and last occurence
        unordered_map <char,pair<int,int>> first_last_occurence;

        for(int i = 0 ; i <  s.size() ; i++)
        {
            if(!first_last_occurence.count(s[i]))
            {
                first_last_occurence[s[i]].first = i;
                first_last_occurence[s[i]].second = i;
            }
            else first_last_occurence[s[i]].second = i;
        }

        // count number of distinct characters between each character's first and last occurence which gives the number of 3 length palindromes that start and end with that character.
        int result = 0;
        for(auto iter : first_last_occurence)
        {
            unordered_set<char> freq;
            if(iter.second.first < s.size() - 1)
            {
                for(int i = iter.second.first + 1 ; i <  iter.second.second ; i++)
                {
                    freq.insert(s[i]);
                }
                result += freq.size();
            }
            
        }
        return result;
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/unique-length-3-palindromic-subsequences/
    */

    