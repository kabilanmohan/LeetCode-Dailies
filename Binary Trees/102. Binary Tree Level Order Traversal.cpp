

    /*
    Time complexity : O(N)
    Space complexity : O(N*M)
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

    // O(N) time but uses 2 queues which is ineffective
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> result;
        if(!root) return result;

        queue<TreeNode*> level_order , temp_level_order;
        level_order.push(root);

        while(!level_order.empty())
        {
            vector<int> temp_result;

            while(!level_order.empty())
            {
                TreeNode* curr = level_order.front();
                level_order.pop();

                temp_result.push_back(curr -> val);

                if(curr -> left)temp_level_order.push(curr -> left);
                if(curr -> right)temp_level_order.push(curr -> right);

            }
            
            result.push_back(temp_result);

            level_order = temp_level_order;
            while (!temp_level_order.empty()) 
            {
                temp_level_order.pop();
            }
        }

        return result;
    }

    // space optimised code , uses only one queue and replaces the 2nd by using the size property
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> result;
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
            result.push_back(temp);   
        }

        return result;
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/binary-tree-level-order-traversal/
    */

    
