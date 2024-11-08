
    /*
    Time complexity : O(log(max(left,right))
    Space complexity : O(1)
    */


class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        while(right > left)
        {
            right = right & (right - 1);
        }
        return left & right;
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/bitwise-and-of-numbers-range
    */

    