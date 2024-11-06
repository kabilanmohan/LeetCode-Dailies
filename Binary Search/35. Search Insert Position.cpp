
    /*
    Time complexity : O(logn)
    Space complexity : O(1)\
    */


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int high = nums.size()-1 , low = 0 , mid ;
        while(low<=high)
        {
            mid = floor((low + high) / 2) ;
            if(nums[mid] < target) low = mid + 1;
            else if(nums[mid] > target) high = mid - 1;
            else return mid;

        }
        return low;
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/search-insert-position/
    */

    