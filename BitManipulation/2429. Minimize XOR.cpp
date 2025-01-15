
    /*
    Time complexity : O(1)
    Space complexity : O(1)
    */


class Solution {
public:
    // initial implementation
    int minimizeXor(int num1, int num2) 
    {
        int num1_one_count = __builtin_popcount(num1) , num2_one_count = __builtin_popcount(num2);

        if(num1_one_count == num2_one_count) return num1;

        else if(num1_one_count > num2_one_count)
        {
            int diff = num1_one_count - num2_one_count;

            for(int i = 0 ; i < diff ; i++)
            {
                num1 &= (num1-1);
            }

            return num1;
        }

        else
        {
            int one = 1;
            while(__builtin_popcount(num1) != __builtin_popcount(num2))
            {
                num1 |= one;
                one <<= 1;
            }

            return num1;
        }
    }

    // A more concise code and different and efficient logic for else case
    int minimizeXor(int num1, int num2) 
    {
        int num1_one_count = __builtin_popcount(num1) , num2_one_count = __builtin_popcount(num2);
        int diff = abs(num1_one_count - num2_one_count);

        if(diff == 0) return num1;

        if(num1_one_count > num2_one_count)
        {
            for(int i = 0 ; i < diff ; i++)
            {
                num1 &= (num1-1);
            }
            return num1;
        }
        else
        {
            for(int i = 0 ; i < diff ; i++)
            {
                num1 |= (num1+1);
            }
            return num1;
        }
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/minimize-xor/
    */

    