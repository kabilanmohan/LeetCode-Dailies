
    /*
    Time complexity : O(n)
    Space complexity : O(n)
    */


class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) 
    {
        int n = words.size();
        vector<int> vowel_prefix (n,0);
        unordered_set<char> vowels = {'a','e','i','o','u'};

        int count = 0 , index = 0;
        for(auto i:words)
        {
            if(vowels.count(i[0]) && vowels.count(i[i.size()-1])) count++;
            vowel_prefix[index] = count;
            index++;
        }

        vector<int> result;
        for(auto i:queries)
        {
            if(i[0] == 0) result.push_back(vowel_prefix[i[1]]);
            else result.push_back(vowel_prefix[i[1]] - vowel_prefix[i[0]-1]);
        }
        return result;
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/count-vowel-strings-in-ranges/
    */

    