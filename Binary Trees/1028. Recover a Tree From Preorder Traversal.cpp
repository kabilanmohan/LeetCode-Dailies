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

    int idx = 0;
    TreeNode* recover_tree(string &traversal , int depth)
    {
        int next_digit_pos = idx;
        while(traversal[next_digit_pos] == '-') next_digit_pos += 1;

        if(next_digit_pos - idx != depth) return NULL;

        int temp = next_digit_pos;
        while(temp < traversal.size() && traversal[temp] != '-') temp++;

        int val = stoi(traversal.substr(next_digit_pos , temp - next_digit_pos));
        idx = temp;

        TreeNode * root = new TreeNode(val);

        root -> left = recover_tree(traversal , depth + 1);
        root -> right = recover_tree(traversal , depth + 1);

        return root; 
    }
    TreeNode* recoverFromPreorder(string traversal) {
        return recover_tree(traversal , 0);
    }
};
