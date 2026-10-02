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
    int max_int=INT_MIN;
    int solve(TreeNode* root){
        if(root==NULL) return 0;
        int l=solve(root->left);    
        int r=solve(root->right);
        int neecha_hi_acha_mil_gaya=l+r+root->val;
        int koi_aik_acha=max(l,r)+root->val;
        int kali_root=root->val;
        max_int=max(max(max_int,neecha_hi_acha_mil_gaya),max(koi_aik_acha,kali_root));
        return max(koi_aik_acha,kali_root);
        }
    int maxPathSum(TreeNode* root) {
        if(root==NULL) return 0;
        solve(root);
        return max_int;
    }
};