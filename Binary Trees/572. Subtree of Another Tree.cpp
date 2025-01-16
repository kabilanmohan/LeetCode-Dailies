

    /*
    Time complexity : O(N * M)
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

    bool helper(TreeNode* node1 , TreeNode* node2)
    {
        if(!node1 && !node2) return true;
        if(!node1 || !node2) return false;

        return (node1 -> val == node2 -> val) && helper(node1 -> left , node2 -> left) && helper(node1 -> right , node2 -> right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) 
    {
        if(!root) return false;
        return helper(root , subRoot) || isSubtree(root -> left , subRoot) || isSubtree(root -> right , subRoot);
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/invert-binary-tree/
    */

    
