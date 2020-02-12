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
    vector<TreeNode*> generateTrees(int n) {
        if (n) return generate_trees(1, n);
        else return vector<TreeNode *>{};
    }
    vector<TreeNode*> generate_trees(int start, int end) {
        vector <TreeNode* > result;
        if (start > end) {
            result.push_back(nullptr);
            return result;
        }
        for (int i = start; i <= end; i++) {
            vector <TreeNode*> left_nodes = generate_trees(start, i - 1);
            vector <TreeNode*> right_nodes = generate_trees(i + 1 ,end);

            for (auto l : left_nodes) {
                for (auto r : right_nodes) {
                    TreeNode* t = new TreeNode(i);
                    t->left = l;
                    t->right = r;
                    result.push_back(t);
                }
            }
        }
        return result;
    }
};

/*
1. 二叉搜索树
2. 卡特兰树
3. 左侧为 start 到 i-1
4. 0特例为 [] 而不是 [[]] 原因是为了完成循环 将左子树设为空
*/
  