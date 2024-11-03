
    /*
    Time complexity : O(n^2)
    Space complexity : O(n)
    */


class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        char temp;
        for(int i = 0 ; i < s.size() ; i++)
        {
            if(goal == s) return true;
            temp = goal[goal.size()-1];
            goal.pop_back();
            goal = temp + goal;
        }
        return false;
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/rotate-string/
    */

    