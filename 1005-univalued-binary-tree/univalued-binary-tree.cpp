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
    bool find=true;
    void findunique(TreeNode* root){
        if(root==NULL) return;
        if(root->left!=NULL ){
            if(root->val!=root->left->val){
                find=false;
                return;
            }
        }
        if(root->right!=NULL ){
            if(root->val!=root->right->val){
                find=false;
                return;
            }
        }
        findunique(root->left);
        findunique(root->right);
    }
    bool isUnivalTree(TreeNode* root) {
        findunique(root);
        return find;
    }
};