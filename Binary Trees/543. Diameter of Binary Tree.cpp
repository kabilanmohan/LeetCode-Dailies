

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
    int diameterOfBinaryTree(TreeNode* root) 
    {
        if(!root) return 0;

        int left = depth(root -> left);
        int right = depth(root -> right); 

        return max({left+right , diameterOfBinaryTree(root -> left) , diameterOfBinaryTree(root -> right)});
    }


    // optimal O(N) code , as the depth function itself visits all the nodes we pass a result variable as reference and calculate the diameter as we find the depth of all nodes.
    int depth(TreeNode* node , int* result)
    {
        if(!node) return 0;

        int left = depth(node -> left , result);
        int right = depth(node -> right , result);

        *result = max(*result , left + right);

        return 1 + max(left , right);
    }
    int diameterOfBinaryTree(TreeNode* root) 
    {
        if(!root) return 0;
        int result = 0;
        
        depth(root , &result);
        return result;
        
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/diameter-of-binary-tree/
    */

    
