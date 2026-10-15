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
    TreeNode* dummy=new TreeNode(-1);
    TreeNode* temp=dummy;
    void helper(TreeNode* root){
        if(root==NULL) return ;

        helper(root->left);
        TreeNode* d1=new TreeNode(root->val);
        temp->right=d1;
        temp=temp->right;
        helper(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        helper(root);

        return dummy->right;
    }
};