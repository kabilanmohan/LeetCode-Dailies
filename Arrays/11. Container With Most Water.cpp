
    /*
    Time complexity : O(n)
    Space complexity : O(1)
    */


class Solution {
public:
    int find_area(int left , int right , int arr_left , int arr_right)
    {
        int h = min(arr_left,arr_right);
        return ((right - left) * h);
    }
    int maxArea(vector<int>& height) {
        int max_area = 0;
        int curr_area = 0;
        int left = 0 , right = height.size() - 1;

        while(left < right)
        {
            curr_area = find_area(left,right,height[left],height[right]);
            if(curr_area > max_area) max_area = curr_area;

            if(height[left] < height[right]) left++;
            else right--;
        }

        return max_area;
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/container-with-most-water/
    */

    