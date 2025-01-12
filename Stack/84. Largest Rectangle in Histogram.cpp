
    /*
    Time complexity : O(n)
    Space complexity : O(n)
    */


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> monotonic_stack; // Stores indices
        int n = heights.size();
        int result = 0;

        for (int i = 0; i < n; i++) 
        {
            while (!monotonic_stack.empty() && heights[i] < heights[monotonic_stack.top()]) 
            {
                int height = heights[monotonic_stack.top()];
                monotonic_stack.pop();
                int width = monotonic_stack.empty() ? i : i - monotonic_stack.top() - 1;
                result = max(result, height * width);
            }
            monotonic_stack.push(i);
        }

        // Process remaining elements in the stack
        while (!monotonic_stack.empty()) 
        {
            int height = heights[monotonic_stack.top()];
            monotonic_stack.pop();
            int width = monotonic_stack.empty() ? n : n - monotonic_stack.top() - 1;
            result = max(result, height * width);
        }

        return result;
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/largest-rectangle-in-histogram/
    */

    