
    /*
    Time complexity : O(n!)
    Space complexity : O(n) -> recursive stack
    */
    
    
    /*
    Additional Notes : None
    */

    
    class Solution {
public:
    int numTilePossibilities(string tiles) 
    {
        int count[26] = {0};
        for(char c : tiles)
        {
            count[c - 'A']++;
        }
        int result = 0;
        permute_seq(count , result);
        return result;
    }

    // backtrack to find all permuations
    void permute_seq(int count[] , int &result)
    {
        for(int i = 0 ; i < 26 ; i++)
        {
            // validate
            if(count[i] == 0) continue;

            //do something
            count[i]--;
            result++;

            // recursive call
            permute_seq(count , result);

            //undo change
            count[i]++;
        }
    }
};
    
    
    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/letter-tile-possibilities/
    */
    
    