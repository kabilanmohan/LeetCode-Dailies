
    /*
    Time complexity : O(N)
    Space complexity : O(1)
    */


class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        int slow1 = 0,fast = 0;
        do
        {
            slow1 = nums[slow1];
            fast = nums[fast];
            fast = nums[fast];

        } while(slow1 != fast);
        
        int slow2 = 0;

        do
        {
            slow1 = nums[slow1];
            slow2 = nums[slow2];

        } while(slow1 != slow2);

        return slow1;
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/find-the-duplicate-number/
    */

    