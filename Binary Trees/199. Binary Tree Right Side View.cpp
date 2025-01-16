

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

    // just doing level order traversal but appending only the last element of each level to the result
    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int> result;
        if(!root) return result;

        queue<TreeNode*> level_order;
        level_order.push(root);

        while(!level_order.empty())
        {
            vector<int> temp;
            int size = level_order.size();
            while(size > 0)
            {
                TreeNode* curr = level_order.front();
                level_order.pop();

                temp.push_back(curr -> val);

                if(curr -> left)level_order.push(curr -> left);
                if(curr -> right)level_order.push(curr -> right);
                
                size--;
            }
            result.push_back(temp[temp.size() - 1]);   
        }

        return result;

    }
};


    /*
    Author : kabilanmohan
    Question Link :https://leetcode.com/problems/binary-tree-right-side-view/
    */

    
