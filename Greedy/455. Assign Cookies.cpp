
    /*
    Time complexity : O(nlogn + mlogn)
    Space complexity : O(1)
    */


class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int result = 0;
        int g_ptr = 0 , s_ptr = 0;
        while (g_ptr < g.size() && s_ptr < s.size())
        {
            if(g[g_ptr] > s[s_ptr]) s_ptr++;
            else
            {
                s_ptr++;
                g_ptr++;
                result++;
            }
        }
        return result;
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/assign-cookies/
    */

    