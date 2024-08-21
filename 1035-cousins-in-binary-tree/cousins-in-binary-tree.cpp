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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.size()>0){
            int n=q.size();
            int count=2;
            for(int i=0;i<n;i++){
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left!=NULL && temp->right!=NULL){
                    if((temp->left->val==x && temp->right->val==y) || temp->right->val==x && temp->left->val==y){
                        return false;
                    }
                }
                if(temp->left!=NULL){
                    q.push(temp->left);
                    if(temp->left->val==x || temp->left->val==y) count--;
                } 
                if(temp->right!=NULL){
                    q.push(temp->right);
                    if(temp->right->val==x || temp->right->val==y) count--;
                } 
            }
            if(count==0) return true;
        }

        return false;
    }
};