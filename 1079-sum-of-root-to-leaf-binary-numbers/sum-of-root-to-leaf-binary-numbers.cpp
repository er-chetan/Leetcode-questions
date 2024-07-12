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
    long long ans=0;
    void binary(TreeNode* root,long long num){
        if(root==NULL) return;
        num=2*num+root->val;
        if(root->left==NULL && root->right==NULL){
            ans+=num;
            return;
        }
        
        binary(root->left,num);
        binary(root->right,num);
    }
    int sumRootToLeaf(TreeNode* root) {
        binary(root,0);
        return ans;
    }
};