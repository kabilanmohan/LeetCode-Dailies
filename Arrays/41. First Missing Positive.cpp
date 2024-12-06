
    /*
    Time complexity : O(n)
    Space complexity : O(1)
    */


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) 
    {

        /*

        This a better solution(using set) but not the optimal one cuz O(n) space used

        unordered_set<int> numset(nums.begin() , nums.end());
        int max = *max_element(nums.begin() , nums.end());

        for(int i = 1; i <= max ; i++)
        {
            if(!numset.count(i)) return i;
        }
        if(max < 0) return 1;
        return max+1;

        */

        auto minmax = minmax_element(nums.begin() , nums.end());
        if(*minmax.second <= 0 || *minmax.first > 1) return 1;

        int size = nums.size();

        for (int i = 0; i < size; i++) {
            // Place each number in its correct position (nums[i] -> index nums[i] - 1)
            while (nums[i] > 0 && nums[i] <= size && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        // Find the first index where the number is incorrect
        for (int i = 0; i < size; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        // If all numbers are in place, return size + 1
        return size + 1;
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/first-missing-positive/
    */

    