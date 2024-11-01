
    /*
    Time complexity : O(n)
    Space complexity : O(n)
    */


class Solution {
public:
    string makeFancyString(string s) {
        if(s.size()<3) return s;
        string ans = "";
        int i = 0 , j = 1, k = 2;
        while(k<s.size())
        {
            if((s[i] == s[j]) && (s[j] == s[k])) {}
            else ans+=s[i];
            i++;
            j++;
            k++;
        }
        ans+=s[i];
        ans+=s[j];
        return ans;
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/delete-characters-to-make-fancy-string/
    */

    