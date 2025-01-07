
    /*
    Time complexity : O(n^2 * L^2)
    Space complexity : O(n)
    */


class Solution {
public:
    vector<string> stringMatching(vector<string>& words) 
    {
        // using string matching either KMP or robin karp reduces time complexity to O(n^2 * L)
        vector<string> result;
        int n =  words.size();

        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0; j < n ; j++)
            {
                if(i == j) continue;
                if(words[j].find(words[i]) != string::npos)
                {
                    result.push_back(words[i]);
                    break;
                }
            }
        }

        return result;
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/string-matching-in-an-array
    */

    