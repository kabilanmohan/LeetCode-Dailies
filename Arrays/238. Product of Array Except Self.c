/*

  Time complexity :  O(n)
  Space complexity : O(1) { excluding the result array }
  
*/


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix_product (n,1);

        int product = 1;

        for(int i = 0 ; i < n ; i++)
        {   
            prefix_product[i] = product;
            product *= nums[i];
        }

        product = 1;

        for(int i = n-1 ; i >= 0 ; i--)
        {   
            prefix_product[i] *= product;
            product = product * nums[i];
        }

        return prefix_product;
    }
};


/*

  Problem Link : https://leetcode.com/problems/product-of-array-except-self/?envType=study-plan-v2&envId=top-interview-150
  Author : kabilanmohan

*/
