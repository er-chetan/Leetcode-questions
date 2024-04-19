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

    TreeNode* iop(TreeNode* root){
        TreeNode* pre = root->left;

        while(pre->right!=NULL){
            pre=pre->right;
        }
        return pre;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        if(root->val==key){
            // case 1 : 0 child
            if(root->left==NULL && root->right==NULL){
                return NULL;
            }
            // case 2 : 1 child
            if(root->left==NULL || root->right==NULL){
                if(root->left!=NULL) return root->left;
                else return root->right;
            }

            // case 3 : 2 child
            if(root->left!=NULL && root->right!=NULL){
                TreeNode* pre = iop(root);
                root->val=pre->val;
                root->left=deleteNode(root->left,pre->val);
            }
        }else if(root->val>key){
            root->left=deleteNode(root->left,key);
        }else{
            root->right=deleteNode(root->right,key);
        }

        return root;
    }
};