class Solution {
public:
    string clearDigits(string s) 
    {
        stack<int> clearing;
        unordered_set<int> digits = {'1','2','3','4','5','6','7','8','9','0'};

        for(char i : s)
        {
            if(!digits.count(i)) clearing.push(i);
            else if(digits.count(i) && !clearing.empty()) clearing.pop();
        }

        string ans = "";
        while(!clearing.empty())
        {
            ans += clearing.top();
            clearing.pop();
        }

        reverse(ans.begin() , ans.end());
        return ans;
    }
};
