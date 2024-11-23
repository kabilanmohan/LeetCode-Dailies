
    /*
    Time complexity : O(m*n)
    Space complexity : O(m*n)
    */


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> spiral;
        int rows = matrix.size();
        int cols = matrix[0].size();
        int max_right = cols - 1, max_down = rows - 1;
        int max_up = 0, max_left = 0; // Initialize correctly
        int curr_row = 0, curr_col = 0; // Start at the top-left corner

        while (max_left <= max_right && max_up <= max_down) {
            // Move right
            for (int i = max_left; i <= max_right; i++) {
                spiral.push_back(matrix[max_up][i]);
            }
            max_up++; // Reduce the top boundary

            // Move down
            for (int i = max_up; i <= max_down; i++) {
                spiral.push_back(matrix[i][max_right]);
            }
            max_right--; // Reduce the right boundary

            // Move left, if still within bounds
            if (max_up <= max_down) {
                for (int i = max_right; i >= max_left; i--) {
                    spiral.push_back(matrix[max_down][i]);
                }
                max_down--; // Reduce the bottom boundary
            }

            // Move up, if still within bounds
            if (max_left <= max_right) {
                for (int i = max_down; i >= max_up; i--) {
                    spiral.push_back(matrix[i][max_left]);
                }
                max_left++; // Reduce the left boundary
            }
        }
        return spiral;
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/spiral-matrix/
    */

    