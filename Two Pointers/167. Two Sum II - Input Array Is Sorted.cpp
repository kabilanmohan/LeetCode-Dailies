
    /*
    Time complexity : O(n)
    Space complexity : O(1)
    */


class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;
        int left = 0  , right = numbers.size() - 1;
        while (right >= left)
        {
            if((numbers[right] + numbers[left]) == target)
            {
                result.push_back(left+1);
                result.push_back(right+1);
                break;
            }
            else if((numbers[right] + numbers[left]) > target)
            {
                right--;
            }
            else if((numbers[right] + numbers[left]) < target)
            {
                left++;
            }
        }
        return result;
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/?envType=study-plan-v2&envId=top-interview-150
    */

    