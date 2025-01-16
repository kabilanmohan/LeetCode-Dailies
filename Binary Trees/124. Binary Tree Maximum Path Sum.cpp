
    /*
    Time complexity : O(N)
    Space complexity : O(10
    */


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int helper(TreeNode* node , int *maximum)
    {
        if(!node) return 0;

        int left = max(0,helper(node -> left , maximum));
        int right = max(0,helper(node -> right , maximum));

        *maximum = max(*maximum, node->val + left + right);
        
        return max(node -> val + left , node -> val + right);
    }
    int maxPathSum(TreeNode* root) 
    {
        if(!root) return 0;

        int maximum = -1e9;
        helper(root , &maximum);

        return maximum;
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/binary-tree-maximum-path-sum/
    */

    