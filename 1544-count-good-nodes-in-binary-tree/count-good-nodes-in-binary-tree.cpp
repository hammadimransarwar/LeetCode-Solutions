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
    int count(TreeNode* root,int max){
       if(root==NULL) return 0;
        int i=0;
        if(root->val>=max) {
            max=root->val;
            i=1;
        }
        return count(root->left,max)+count(root->right,max)+i; 
    }
    int goodNodes(TreeNode* root) {
        if(root==NULL) return 0;
        return count(root->left,root->val)+count(root->right,root->val)+1;
    }
};