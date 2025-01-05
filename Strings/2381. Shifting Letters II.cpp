
    /*
    Time complexity : O(n)
    Space complexity : O(1)
    */


class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) 
    {
        vector<int> final_shift(s.size() + 1 , 0); // array to store final shift values

        // line sweep algorithm

        for(auto i : shifts)
        {
            if(i[2] == 1) 
            {
                final_shift[i[0]] ++;
                final_shift[i[1] + 1] --;
            }
            else 
            {
                final_shift[i[0]] --;
                final_shift[i[1] + 1] ++;
            }

        }

        // accumulate all the shifts ( basically prefix sum)
        for(int i = 1 ; i < final_shift.size() ; i++) final_shift[i] += final_shift[i-1];

        for(int i = 0 ; i < s.size() ; i++)
        {
            final_shift[i] = final_shift[i] % 26;
            s[i] = (s[i] - 'a' + final_shift[i] + 26) % 26 + 'a';
        }

        return s;
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/shifting-letters-ii/
    */

    