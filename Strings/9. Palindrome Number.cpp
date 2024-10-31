
    /*
    Time complexity : O(n)
    Space complexity : O(n)
    */


class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        string num = to_string(x);
        int left = 0;
        int right = num.size()-1;

        while(left<=right)
        {
            if(num[left] != num[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/palindrome-number/
    */

    