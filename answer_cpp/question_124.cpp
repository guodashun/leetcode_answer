/*
最初的想法是以下两行代码：
    if (root == nullptr) return 0;
    return max(root->val, root->val + max(maxPathSum(root->left), maxPathSum(root->right)));
这是一种后序遍历
这样可以保证每次返回左右子树的最大路径
但还有第三种情况：左+根+右，这个是要单独存的
*/

// 思路：分治法，分为三种情况：左子树最大路径和最大，右子树最大路径和最大，左右子树最大加根节点最大，需要保存两个变量：一个保存子树最大路径和，一个保存左右加根节点和，然后比较这个两个变量选择最大值即可
class Solution {
public:
    int res = INT_MIN;
    int maxPathSum(TreeNode* root) {
        helper(root);
        return res;
    }
    int helper(TreeNode* root) {
        if (root == nullptr) return 0;
        int left = max(helper(root->left), 0);
        int right = max(helper(root->right), 0);

        // 这一步很妙，看似在比较各个左+右+根，实际上也包含了与左和右的比较
        // res表示子树最大路径和
        res = max(res, root->val + left + right);

        return root->val + max(left, right);
    }
};
