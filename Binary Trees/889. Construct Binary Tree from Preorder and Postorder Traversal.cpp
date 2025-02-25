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
    TreeNode* pre_post(vector<int> pre, vector<int> post)
    {
        if(pre.size() == 0 || post.size() == 0) return NULL;

        int val = pre[0];
        TreeNode * root = new TreeNode(val);

        if(pre.size() == 1) return root;

        pre.erase(pre.begin());
        post.pop_back();


        auto it = find(post.begin() , post.end() , pre[0]);
        int idx = distance(post.begin() , it) + 1;

        root -> left = pre_post(vector<int>(pre.begin() , pre.begin() + idx) , 
                                        vector<int>(post.begin(), post.begin() + idx));

        root -> right = pre_post(vector<int>(pre.begin() + idx, pre.end()) , 
                                        vector<int>(post.begin() + idx, post.end()));

        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) 
    {
        return pre_post(preorder , postorder);
    }
};
