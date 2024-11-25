
    /*
    Time complexity : O(nlogn)
    Space complexity : O(1)
    */


class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());

        int left = 0 , right = nums.size() - 1;
        int count = 0;
        int curr_sum = 0;

        while(left < right)
        {   
            curr_sum = nums[left]+nums[right];
            if(curr_sum > k) right --;
            else if(curr_sum < k) left ++;
            else
            {
                count++;
                left++;
                right--;
            }
        }
        return count;
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/max-number-of-k-sum-pairs/
    */

    