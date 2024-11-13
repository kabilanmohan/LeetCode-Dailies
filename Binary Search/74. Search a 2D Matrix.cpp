
    /*
    Time complexity : O(logm + logn)
    Space complexity : O(1)
    */


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rownum = matrix.size();
        int colnum = matrix[0].size();

        int top = 0, bottom = rownum - 1, row = 0, mid = 0;

        // Search for the correct row
        while (top <= bottom) {
            mid = (top + bottom) / 2;
            if (matrix[mid][colnum - 1] == target) return true;
            if (matrix[mid][colnum - 1] > target) bottom = mid - 1;
            else top = mid + 1;
        }

        row = top;
        if (row >= rownum) row--; // Adjust if we went past last row

        // Ensure the row is within bounds
        if (row < 0) return false;

        int left = 0, right = colnum - 1;

        // Binary search within the row
        while (left <= right) {
            mid = (left + right) / 2;
            if (matrix[row][mid] == target) return true;
            if (matrix[row][mid] > target) right = mid - 1;
            else left = mid + 1;
        }

        return false;
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/search-a-2d-matrix/?envType=study-plan-v2&envId=top-interview-150
    */

    