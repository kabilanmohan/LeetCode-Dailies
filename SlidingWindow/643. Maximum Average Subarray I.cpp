
    /*
    Time complexity : O(N)
    Space complexity : O(1)
    */


class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) 
    {
        int left = 0 , right = k - 1;

        double sum = 0;
        for(int i = left ; i <= right ; i++) sum+=nums[i];
        if(nums.size() == k) return sum / k;

        double result = sum;

        while(right < nums.size())
        {
            sum -= nums[left];
            left++;

            right++;
            sum += nums[right];

            result = max(result,sum);
        }
        return result / k;
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/maximum-average-subarray-i/
    */

    