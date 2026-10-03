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
    string serilaizehelper(TreeNode* root){
        if(root==NULL){
            return "N,";
        }
        string endoded=to_string(root->val);
        endoded+=',';
        endoded+=serilaizehelper(root->left);
        endoded+=serilaizehelper(root->right);
        return endoded;
    }
    string serialize(TreeNode* root) {
        string seril_str=serilaizehelper(root);
        return seril_str;
    }
    vector<string> get_array_of_string(string data){
        string temp;
        vector<string> arr;
        stringstream ss(data);
        while(getline(ss, temp, ',')){
            arr.push_back(temp);
            }
            return arr;
    }
    TreeNode* built_tree(vector<string> &arr_vect,TreeNode* root,int &i){
        if(i>=arr_vect.size()||i<arr_vect.size()&&arr_vect[i]=="N"){
            i++;
            return NULL;
        }
        int val=stoi(arr_vect[i++]);
        TreeNode* temp=new TreeNode(val);            
        temp->left=built_tree(arr_vect,temp->left,i);
        temp->right=built_tree(arr_vect,temp->right,i);
        return temp;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> arr_vect=get_array_of_string(data);
        int i=0;
        return built_tree(arr_vect,NULL,i);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));