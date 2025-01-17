
    /*
    Time complexity : O(N)
    Space complexity : O(1)
    */


class Solution {
public:

    // brute force approach O(2n) time and o(N) space
    bool doesValidArrayExist(vector<int>& derived) 
    {
        int n = derived.size();
        vector<int> original(n , 0);

        original[0] = 0;
        for(int i = 1; i < n ; i++)
        {
            original[i] = derived[i-1] ^ original[i-1];
        }
        if(original[n-1] ^ original[0] == derived[n-1]) return true;

        original[0] = 1;
        for(int i = 1; i < n ; i++)
        {
            original[i] = derived[i-1] ^ original[i-1];
        }
        if(original[n-1] ^ original[0] == derived[n-1]) return true;

        return false;
    }

    // better approach -> same time but O(1) space
    bool doesValidArrayExist(vector<int>& derived) 
    {
        int n = derived.size() ,original;

        original = 0;
        for(int i = 1; i < n ; i++)
        {
            original ^= derived[i-1];
        }
        if(original ^ 0 == derived[n-1]) return true;

        original = 1;
        for(int i = 1; i < n ; i++)
        {
            original ^= derived[i-1];
        }
        if(original ^ 1 == derived[n-1]) return true;

        return false;
    }

    // optimal code 
    // if xor the entire derived array it should result in 0 because 
    // (original[0] ^ original[1]) ^ (original[1] ^ original[2]) ^ (original[2] ^ original[0]) will give 0
    bool doesValidArrayExist(vector<int>& derived) 
    {
        int n = derived.size() , result = 0;

        for(int i :  derived) result ^= i;
        
        if(result == 0) return true;
        return false;
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/neighboring-bitwise-xor/
    */

    
