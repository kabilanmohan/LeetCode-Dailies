/*
  Time Complexity : O(n)
  Space Complexity : O(n)
*/


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash(nums.begin(), nums.end());
        int maxf = 0;
        for (int n : nums) {
            if (!hash.count(n - 1)) { 
                int count = 1;
                int current = n;
                while (hash.count(current + 1)) {
                    count++;
                    current++;
                }
                maxf = max(maxf, count);
            }
        }
        return maxf;
    }
};

/* 
 problem link : https://leetcode.com/problems/longest-consecutive-sequence
 author : kabilanmohan
*/
