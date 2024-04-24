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
    int minival(TreeNode* root){
        if(root==NULL) return INT_MAX;
        int left=minival(root->left);
        int right=minival(root->right);
        return min(root->val,min(left,right));
    }
    void helper(TreeNode* root,int mini,int& smini,int& sele){
        if(root==NULL) return;
        if(mini!=root->val && smini>abs(mini-root->val) ){
            smini=abs(mini-root->val);
            sele=root->val;
        }
        helper(root->left,mini,smini,sele);
        helper(root->right,mini,smini,sele);
    }
    int findSecondMinimumValue(TreeNode* root) {
        
        int mini=minival(root);
        int smini=INT_MAX;
        int sele=INT_MAX;
        helper(root,mini,smini,sele);

        if(smini==INT_MAX && sele==INT_MAX) return -1;


        return sele;
    }
};