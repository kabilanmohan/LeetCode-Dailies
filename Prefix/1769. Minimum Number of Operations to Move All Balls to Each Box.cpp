
    /*
    Time complexity : O(n)
    Space complexity : O(n)
    */


class Solution {
public:

    // O(n^2) solution -> easy to come up with
    vector<int> minOperations(string boxes) 
    {
        vector<int> one_index;
        for(int i = 0 ; i < boxes.size() ; i++)
        {
            if(boxes[i] == '1') one_index.push_back(i);
        }

        vector<int> result(boxes.size() , 0);

        for(int i = 0 ; i < boxes.size() ; i++)
        {
            for(int j = 0 ; j < one_index.size() ; j++) result[i] += abs(i - one_index[j]);
        }

        return result;
    }

    // O(n) solution
    vector<int> minOperations(string boxes)
    {
        int n = boxes.size();
        
        vector<int> prefix(n,0) , suffix(n,0); //prefix array says how many steps are required to shift ones in the left hand side of that index and suffix speaks about right hand side
        int ones_faced = 0;

        for(int i = 1 ; i < n ; i++)
        {
            if(boxes[i-1] == '1') ones_faced++;
            prefix[i] = prefix[i-1] + ones_faced; // important logic ( write a test case to visualize it)
        }

        ones_faced = 0;
        for(int i = n - 2 ; i >= 0 ; i--)
        {
            if(boxes[i+1] == '1') ones_faced++;
            suffix[i] = suffix[i+1] + ones_faced;
        }
        
        for(int i = 0 ; i < n ; i++) prefix[i] += suffix[i];
        return prefix;

    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box
    */

    