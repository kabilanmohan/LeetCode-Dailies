

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

    // O(N^2) time complexity because for every node we are calling the depth function which runs an extra O(N)
    int depth(TreeNode* node)
    {
        if(!node) return 0;
        return 1 + max(depth(node -> left) , depth(node -> right));
    }
    bool isBalanced(TreeNode* root) 
    {
        if(!root) return true;

        int left = depth(root -> left);
        int right = depth(root -> right);

        return (abs(right - left) <= 1) & isBalanced(root -> left) & isBalanced(root -> right);
    }

// optimal O(N) code , as the depth function itself visits all the nodes we pass a result variable as reference and calculate the isbalanced check as we find the depth of all nodes.
    int depth(TreeNode* node , bool* result)
    {
        if(!node) return 0;

        int left = depth(node -> left , result);
        int right = depth(node -> right , result);

        *result = *result & (abs(right - left) <= 1);

        return 1 + max(left , right);
    }
    bool isBalanced(TreeNode* root) 
    {
        if(!root) return true;

        bool result = true;
        depth(root , &result);
        return result;

    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/balanced-binary-tree/
    */

    
