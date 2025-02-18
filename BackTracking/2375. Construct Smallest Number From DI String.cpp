
    /*
    Time complexity : O(2^n)
    Space complexity : O(N)
    */
    
    
    /*
    Additional Notes : None
    */

    
    class Solution {
public:

    bool generate_number(int idx , int start , int end , string &pattern , string &result , vector<bool> &visited)
    {
        if(idx == result.size()) return true;
        if(start < 1 || end > 9) return false;

        for(int i = start ; i <= end ; i++)
        {
            if(visited[i]) continue;

            visited[i] = true;
            char c = '0' + i;
            result[idx] = c;

            if(idx == pattern.size() || pattern[idx] == 'I')
            {
                if(generate_number(idx+1 , i+1 , 9 , pattern , result , visited)) return true;
            }
            else
            {
                if(generate_number(idx+1 , 1 , i-1 , pattern , result , visited)) return true;
            }

            visited[i] = false;
            result[idx] = '0';
        }
        return false;
    }
    string smallestNumber(string pattern) 
    {
        int n = pattern.size()+1;
        string result(n , '0');
        vector<bool> visited(10 , false);

        generate_number(0 , 1 , 9 , pattern , result , visited);
        return result; 
    }
};
    
    
    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/construct-smallest-number-from-di-string/
    */
    
    