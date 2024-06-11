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
    bool find=false;
    void findres(TreeNode* root, int rem,TreeNode* same){
        if(root==NULL) return;
        if(root->val==rem && root!=same){
            cout<<root->val<<rem;
            find=true;
            return;
        }
        if(rem<root->val){
            findres(root->left,rem,same);
        }else{
            findres(root->right,rem,same);
        }
    }

    void findval(TreeNode* root, int k,TreeNode* temp){
        if(root==NULL) return;
        findres(temp,k-root->val,root);
        
        if(find==true) return;
        findval(root->left,k,temp);
        findval(root->right,k,temp);
    }

    bool findTarget(TreeNode* root, int k) {
        TreeNode* temp=root;
        findval(root,k,temp);
        return find;
    }
};