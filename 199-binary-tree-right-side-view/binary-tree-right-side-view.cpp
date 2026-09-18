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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>Res;
        if(root==NULL) return Res;
        queue<TreeNode*>Level;
        int level_size;
        Level.push(root);
        level_size=Level.size();
        while(!Level.empty()){
            TreeNode *current=Level.front();
            Level.pop();
            level_size--;
            if(current->left) Level.push(current->left);
            if(current->right) Level.push(current->right);
            if(level_size==0){
                Res.push_back(current->val);
                level_size=Level.size();
            }
        }
        return Res;
    }
};