
    /*
    Time complexity : O(nlogk)
    Space complexity : O(k)
    */


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        priority_queue<int,vector<int>,greater<>> topk;

        for(auto iter: nums)
        {   
            topk.push(iter);
            if(topk.size() > k) topk.pop();
        }

        return topk.top();
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/kth-largest-element-in-an-array/
    */

    