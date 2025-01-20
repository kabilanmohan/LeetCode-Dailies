
    /*
    Time complexity : O(n)
    Space complexity : O(n)
    */


class Solution {
public:
    string removeKdigits(string num, int k) 
    {
        stack<char> kdstack;
        for(int i = 0 ; i < num.size(); i++)
        {
            while(!kdstack.empty() && k && kdstack.top() > num[i])
            {
                kdstack.pop();
                k--;
            }
            kdstack.push(num[i]);
        }

        while(!kdstack.empty() && k)
        {
            kdstack.pop();
            k--;
        }   

        string ans = "";
        while(!kdstack.empty())
        {
            ans += kdstack.top();
            kdstack.pop();
        }
        reverse(ans.begin() , ans.end());

        string final_ans = ""; 
        for(char i : ans)
        {
            if(i != '0' || final_ans.size()) final_ans += i;
        }
        return final_ans.size() > 0 ? final_ans : "0";
    }   
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/remove-k-digits/
    */

    