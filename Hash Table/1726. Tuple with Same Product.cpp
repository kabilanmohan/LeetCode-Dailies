
    /*
    Time complexity : O(N^2)
    Space complexity : O(n)
    */


class Solution {
public:
    int tupleSameProduct(vector<int>& nums) 
    {
        unordered_map<int,int> products;
        int count = 0;

        for(int i = 0 ; i < nums.size() ; i++)
        {
            for(int j = 0 ; j < i ; j++)
            {
                int temp = nums[i] * nums[j];
                if(!products[temp]) products[temp] = 1;
                else 
                {
                    count += products[temp] * 8;
                    products[temp]++;
                }
            }
        }
        return count;
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/tuple-with-same-product/
    */

    