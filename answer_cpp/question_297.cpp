/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root){
            return ""; // 判空
        }
        ostringstream out;
        queue<TreeNode*> bfs;
        bfs.push(root);
        while(!bfs.empty()){
            // 迭代法
            TreeNode* temp = bfs.front();
            bfs.pop();
            if(temp){
                out<< temp -> val << " ";
                bfs.push(temp -> left);
                bfs.push(temp -> right);
            }
            else{
                out<< "null "; // 注意 null 后面有空格
            }
        }
        return out.str(); // out 用来将树转成字符串，元素之间用空格分隔
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()){
            return nullptr; // 判空
        }
        istringstream input(data);
        string info;
        vector<TreeNode*> res; // res 用来将字符串里每个元素转成 TreeNode* 形式的元素
        while(input >> info){
            if(info == "null"){ // 注意 null 后面没空格（因为空格是用来分隔字符串的，不属于字符串）
                res.push_back(nullptr);
            }
            else{
                res.push_back(new TreeNode(stoi(info)));
            }
        }
        int pos = 1;
        for(int i = 0; pos < res.size(); ++i){
            // 本循环将 res 中的所有元素连起来，变成一棵二叉树
            if(!res[i]){
                continue;
            }
            res[i] -> left = res[pos++]; // pos 此时指向左子树，++后指向右子树
            if(pos < res.size()){
                res[i] -> right = res[pos++]; // pos 此时指向右子树，++后指向下一个节点的左子树
            }
        }
        return res[0];
    }
};


// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

// 使用了steam  很方便 （空格分隔）
// stoi
// 反序列化的pos很关键
// 例子的二叉树序列化之后为[1 2 3 null null 4 5 null null null null]

