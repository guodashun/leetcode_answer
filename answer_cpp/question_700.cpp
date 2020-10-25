/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr) return nullptr;
        if (root->val > val)
            root = searchBST(root->left, val);
        else if (root->val < val)
            root = searchBST(root->right, val);
        else if (root->val == val)
            return root;
        return root;
    }
};

// else if 的使用
