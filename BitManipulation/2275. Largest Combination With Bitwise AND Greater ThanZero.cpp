
    /*
    Time complexity : O(n)
    Space complexity : O(1)
    */


class Solution {
public:
    int largestCombination(vector<int>& candidates) {

        vector<int> bitCount(32,0);

        for(int i:candidates)
        {
            for(int j = 0 ; j< 32 ;j++)
            {
                if(i & (1 << j)) bitCount[j]++;
            }
        }
        int maxC = 0;
        for(int i:bitCount) maxC = max(maxC, i);

        return maxC;
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero/
    */

    