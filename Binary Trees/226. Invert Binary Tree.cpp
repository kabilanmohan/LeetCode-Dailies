
    /*
    Time complexity : O(N)
    Space complexity : O(1)
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

    void invertTree_helper(TreeNode* node)
    {
        if(!node -> left && !node -> right) return;
        
        if(node -> left) invertTree_helper(node -> left);
        if(node -> right) invertTree_helper(node -> right);

        TreeNode *temp = node -> left;
        node -> left = node -> right;
        node -> right = temp;
    }
    TreeNode* invertTree(TreeNode* root) 
    {
        if(!root) return root;
        invertTree_helper(root);
        return root;
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/invert-binary-tree/
    */

    