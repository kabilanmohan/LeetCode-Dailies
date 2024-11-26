/*  
  Time Complexity : O(n)
  Space Complexity : O(n)
*/


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> polish;

        if(tokens.size() == 1) return stoi(tokens[0]);
        polish.push(stoi(tokens[0]));
        polish.push(stoi(tokens[1]));

        int iter = 2;
        while(!polish.empty() && iter < tokens.size())
        {
            string s = tokens[iter];
            if(s == "+" || s == "-" || s == "/" || s == "*")
            {
                int num1 = polish.top();
                polish.pop();
                int num2 = polish.top();
                polish.pop();
                if(s == "+")polish.push(num2 + num1);
                if(s == "-")polish.push(num2 - num1);
                if(s == "*")polish.push(num2 * num1);
                if(s == "/")polish.push(num2 / num1);
            }
            else polish.push(stoi(tokens[iter]));
            iter++;
        }
        return polish.top();
    }
};


/*
  problem link : https://leetcode.com/problems/evaluate-reverse-polish-notation/
  author :  kabilanmohan
*/
