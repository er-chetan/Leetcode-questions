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
    string str;
    void helper(TreeNode* root){
        if(root==NULL) return ;

       str += to_string(root->val);
        
        if(root->left==NULL && root->right==NULL){
           return;
        }else if(root->left==NULL && root->right!=NULL){
            str.push_back('(');
            str.push_back(')');
            str.push_back('(');
            helper(root->right);
            str.push_back(')');
            return;
        }else{
            str.push_back('(');
            helper(root->left);
            if(root->right){
                str.push_back(')');
                str.push_back('(');
                helper(root->right);
            }
            str.push_back(')');
        }

    }
    string tree2str(TreeNode* root) {
        helper(root);
        return str;
    }
};