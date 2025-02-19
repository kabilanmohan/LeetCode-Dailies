
    /*
    Time complexity : O(3^n)
    Space complexity : O(n) -> recursive stack
    */
    
    
    /*
    Additional Notes : None
    */

    
    class Solution {
public:
    void generate_strings(int idx , int prev , int n ,string &temp , vector<string> &result)
    {
        if(idx == n)
        {
            result.push_back(temp);
            return;
        }

        for(int i = 0 ; i < 3 ; i++)
        {
            if(i == prev) continue;

            char c = 'a' + i;
            temp[idx] = c;
            generate_strings(idx+1 , i , n , temp , result);

            temp[idx] = 'z';
        }
    }
    string getHappyString(int n, int k) 
    {
        string temp(n , 'z');
        vector<string> result;

        generate_strings(0, -1 , n , temp , result);

        if(result.size() < k) return "";
        return result[k - 1];
    }
};
    
    
    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/
    */
    
    