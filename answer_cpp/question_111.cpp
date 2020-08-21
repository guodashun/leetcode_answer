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
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        queue<TreeNode*> que;
        que.push(root);
        TreeNode* cur;
        int depth = 1;
        while(!que.empty()) {
            // cur = que.front();
            // que.pop();
            // if (cur->left == nullptr && cur->right == nullptr) {
            //     return depth;
            // }
            // if (cur->left != nullptr) {
            //     que.push(cur->left);
            // }
            // if (cur->right != nullptr) {
            //     que.push(cur->right);
            // }
            int num=que.size();
            // cout << num << endl;
            while(num-->0){
                cur = que.front();
                que.pop();
                if (cur->left == nullptr && cur->right == nullptr) {
                    return depth;
                }
                if (cur->left != nullptr) {
                    que.push(cur->left);
                }
                if (cur->right != nullptr) {
                    que.push(cur->right);
                }
            }
        depth++;
        }
        return depth;
    }

};

// c++ queue理解
// push emplace区别
// depth++ 执行（上一段少了一个for循环）
