
    /*
    Time complexity : O(n*2^n)
    Space complexity : O(n*2^n)
    */
    
    
    /*
    Additional Notes : None
    */

    
    class Solution {
public:

    // approach is to geneare all possible substrings and in base case check whether the partioned substrings sum equals the original number

    // Space and Time -> O(n*2^n)

    bool generate_substring_and_check(int idx , string &s , vector<string> &substrings , int substring_idx , int original)
    {
        if(idx == s.size())
        {
            int sum = 0;
            for(string i : substrings)
            {
                if(!i.empty()) sum += stoi(i);
            }
            return original == sum;
        }

        bool pick = false , no_pick = false;

        // pick case
        substrings[substring_idx].push_back(s[idx]);
        pick = generate_substring_and_check(idx + 1 , s , substrings , substring_idx , original);
        substrings[substring_idx].pop_back();

        // no pick case but ensure that always a string is started after no pick
        if((substring_idx + 1) < substrings.size())
        {
            substrings[substring_idx + 1].push_back(s[idx]);
            no_pick = generate_substring_and_check(idx + 1 , s , substrings , substring_idx + 1 , original);
            substrings[substring_idx + 1].pop_back();
        }

        return pick || no_pick;

    }
    int punishmentNumber(int n) 
    {
        int result = 0;
        for(int i = 1;  i <= n ; i++)
        {
            string temp = to_string(i*i);
            vector<string> temp_substring(temp.size() , "");
            if(generate_substring_and_check(0 , temp , temp_substring , 0 , i))
            {
                result += i*i;
            }
        }
           return result;
    }


    // better appraoch


};
    
    
    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/find-the-punishment-number-of-an-integer/
    */
    
    