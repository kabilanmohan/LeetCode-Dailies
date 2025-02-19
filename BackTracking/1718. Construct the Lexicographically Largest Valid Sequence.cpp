
    /*
    Time complexity : O(n!)
    Space complexity : O(n)
    */
    
    
    /*
    Additional Notes : None
    */

    
    class Solution {
public:

    bool construct(int idx , int size , int n , vector<int> &result , vector<bool> &visited)
    {
        // base case
        if(idx == size) return true;

        // Try elements
        for(int num = n ; num >= 1 ; num--)
        {
            // validation steps
            if(visited[num]) continue;
            if(num > 1 && (idx + num >= size || result[idx+num] != -1)) continue;

            // try decision
            visited[num] = true;
            result[idx] = num;
            if(num > 1) result[idx+num] = num;

            int new_idx = idx + 1;
            while(new_idx < size && result[new_idx] != -1) new_idx++;

            //recursive call
            if(construct(new_idx , size , n , result , visited)) return true;

            //Undo decision (backtrack)
            visited[num] = false;
            result[idx] = -1;
            if(num > 1) result[idx+num] = -1;
        }
        return false;
    }
    vector<int> constructDistancedSequence(int n) 
    {
        int size = 2*n - 1;
        vector<int> result(size , -1);
        vector<bool> visited(size , false);
        construct(0 , size , n , result , visited);

        return result;

    }
};
    
    
    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/construct-the-lexicographically-largest-valid-sequence/
    */
    
    