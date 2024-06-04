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
    void helper(TreeNode* root, int val, int depth,int level){
        if(root==NULL){
            return;
        }
        if(level>depth-1){
            return;
        }
        cout<<root->val<<" "; 
        if(level==depth-1){
            TreeNode* temp1=root->left;
            TreeNode* temp2=root->right;
            TreeNode* newleft=new TreeNode(val);
            TreeNode* newright=new TreeNode(val);
            root->left=newleft;
            root->right=newright;
            root->left->left=temp1;
            root->right->right=temp2;
            return;
        }
        level++;
        helper(root->left,val,depth,level);
        helper(root->right,val,depth,level);

    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(1==depth){
            TreeNode* temp=new TreeNode(val);
            temp->left=root;
            return temp;
        }
        helper(root,val,depth,1);
        return root;
    }
};