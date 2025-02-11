class Solution {
public:
    // stack approach -> O(M*N)
    string removeOccurrences(string s, string part) 
    {
        if(part.size() > s.size()) return s;
        stack<char> char_stack;
        int n2 = part.size();

        for(char i : s)
        {
            char_stack.push(i);
            
            if(char_stack.size() >= n2)
            {
                int iter = n2-1;
                stack<char> temp;

                while(!char_stack.empty() && iter >= 0 && char_stack.top() == part[iter])
                {
                    temp.push(char_stack.top());
                    char_stack.pop();
                    iter--;
                }

                if(iter >= 0 )
                {
                    while(!temp.empty())
                    {
                        char_stack.push(temp.top());
                        temp.pop();
                    }
                }
            } 
        }   

        string ans;
        while(!char_stack.empty())
        {
            ans += char_stack.top();
            char_stack.pop();
        }     

        reverse(ans.begin() , ans.end());
        return ans;
    }


    // same O(M*N) but erase and find more optimized than a stack
    string removeOccurrences(string s, string part) 
    {
        while (s.find(part) != string::npos) 
        {
            s.erase(s.find(part), part.size());
        }
        return s;
    }
};
