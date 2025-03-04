
    /*
    Time complexity : O(n)
    Space complexity : O(1)
    */


class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0|| (x!=0 &&x%10==0)) return false;
        int sum=0;
        while(x>sum)
        {
            sum = sum*10+x%10;
            x = x/10;
        }
        return (x==sum)||(x==sum/10);
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/palindrome-number/
    */

    