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
class FindElements {
public:
    unordered_set<int> nodes;
    void recover_tree(TreeNode* node)
    {
        int temp = node -> val;
        if(node -> left)
        {
            node -> left -> val = 2 * temp + 1;
            nodes.insert(2*temp + 1);
            recover_tree(node -> left);
        }
        if(node -> right)
        {
            node -> right -> val  =2 * temp + 2;
            nodes.insert(2*temp + 2);
            recover_tree(node -> right);
        }
        return;
    }
    FindElements(TreeNode* root) 
    {
        root -> val = 0;
        nodes.insert(0);
        recover_tree(root);
    }
    
    bool find(int target) {
        return nodes.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
