
    /*
    Time complexity : O(n)
    Space complexity : O(n)
    */


class Solution {
public:
    bool isValid(string s) {
        stack<char> s_stack;
        for(auto &iter : s)
        {
            
            if(iter == '{' || iter == '(' || iter == '[') s_stack.push(iter);
            else
            {
                if (s_stack.empty()) return false;
                if((iter == '}' && s_stack.top() == '{') ||
                (iter == ']' && s_stack.top() == '[') ||
                (iter == ')' && s_stack.top() == '('))
                {
                    s_stack.pop();
                }
                else return false;
            }
           
        }
        return s_stack.empty();
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/valid-parentheses/
    */

    