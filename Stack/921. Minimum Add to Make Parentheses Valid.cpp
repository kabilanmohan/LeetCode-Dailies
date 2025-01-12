
    /*
    Time complexity : O(n)
    Space complexity : O(N)
    */


class Solution {
public:
    int minAddToMakeValid(string s) 
    {
        stack<char> parentheses_stack;

        for(char i : s)
        {
            if(i == '(') parentheses_stack.push('(');
            else
            {
                if(!parentheses_stack.empty() && parentheses_stack.top() == '(') parentheses_stack.pop();
                else parentheses_stack.push(')');
            }
        }

        return parentheses_stack.size();
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
    */

    