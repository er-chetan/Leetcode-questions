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
    vector<int> ans;
    void left_view(TreeNode* root){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            return;
        }
        
        ans.push_back(root->val);
        left_view(root->left);
        if(root->left==NULL){
            left_view(root->right);
        }
    
    }
    void bottom_view(TreeNode* root){
        if(root==NULL) return;
        

        if(root->left==NULL && root->right==NULL){
            
            ans.push_back(root->val);
            return;
        }
        bottom_view(root->left);
        bottom_view(root->right);
    
    }

    void right_view(TreeNode* root){
        if(root==NULL) return;
        
        if(root->left==NULL && root->right==NULL){
            return;
        }
        
        right_view(root->right);
        if(root->right==NULL){
            right_view(root->left);
        }

        ans.push_back(root->val);
    
    }
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        ans.push_back(root->val);

        if(root->left || root->right){
            left_view(root->left);
            bottom_view(root);
            right_view(root->right);
        }
        

    
        return ans;
    }
};