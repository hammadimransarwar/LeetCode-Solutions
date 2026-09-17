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
    vector<vector<int>>Res;
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL) return Res;
        queue<TreeNode*>track;
        track.push(root);
        int level_size=track.size();
        vector<int>level;
        while(!track.empty()){
           if(level_size==0){
            Res.push_back(level);
            level_size=track.size();
            level.clear();
           }
           TreeNode* current=track.front();
           track.pop();
           level.push_back(current->val);
           level_size--;
           if(current->left) track.push(current->left);
           if(current->right) track.push(current->right);
        }
        Res.push_back(level);
        return Res;
    }
};