
    /*
    Time complexity : O(n)
    Space complexity : O(n)
    */


class Solution {
public:
    bool canBeValid(string s, string locked) 
    {
        if(s.size() % 2 != 0) return false;

        stack <int> star, open; // store index of open bracket and star

        for(int i = 0 ; i < s.size() ; i++) if(locked[i] == '0') s[i] = '*'; // make all unlocked as *

        for(int i = 0 ; i < s.size() ; i++)
        {
            if(s[i] == '(') open.push(i);
            else if(s[i] == '*') star.push(i);
            else
            {
                if(!open.empty()) open.pop(); // first pop a locked ( when encountering a )
                else if(!star.empty()) star.pop(); // if no locked present pop a star
                else return false;
            }
        }
        while(!open.empty()) 
        {
            if(!star.empty() && star.top() > open.top()) // match a locked ( with a * that occured after the (
            {
                star.pop();
                open.pop();
            }
            else break;
        }

        if(!open.empty()) return false;
        if(star.size() % 2 != 0) return false;
        return true;
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/
    */

    