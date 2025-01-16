

    /*
    Time complexity : O(N)
    Space complexity : O(N)
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

    int helper(TreeNode* node , int maximum)
    {
        if(!node) return 0;
        if(node -> val >=  maximum) return 1 + helper(node -> left , node -> val) + helper(node -> right , node -> val);
        else return helper(node -> left , maximum) + helper(node -> right , maximum);
    }
    int goodNodes(TreeNode* root) 
    {
        if(!root) return 0;
        return (helper(root , root -> val));
    }
};


    /*
    Author : kabilanmohan
    Question Link :https://leetcode.com/problems/count-good-nodes-in-binary-tree/
    */

    
