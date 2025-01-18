    /*
    Time complexity : O(32) -> O(1)
    Space complexity : O(1)
    */


class Solution {
public:
    int getSum(int a, int b) 
    {
        int xor_val = a ^ b; // XOR gives sum without carry
        int carry = a & b;   // AND gives the carry

        while(carry != 0)
        {
            int shifted_carry = carry << 1; // Shift carry to the left
            carry = xor_val & shifted_carry; // New carry is based on current xor_val and shifted_carry
            xor_val = xor_val ^ shifted_carry; // Update xor_val (sum without new carry)
        }

        return xor_val;
    }
};



    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/sum-of-two-integers/
    */
