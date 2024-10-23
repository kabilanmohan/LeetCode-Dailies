
    """
    Time complexity : O(n)
    Space complexity : O(1)
    """


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        dic = {}
        n = len(nums)

        for i in range(n):
            comp = target - nums[i]
            if comp in dic:
                return [i , dic[comp]]
            dic[nums[i]] = i


    """
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/two-sum/description/
    """

    