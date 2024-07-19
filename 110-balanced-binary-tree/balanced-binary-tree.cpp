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
    int heightBalance(TreeNode* root,int depth){
        if(root==NULL){
            return depth;
        }
        
        int left=heightBalance(root->left,depth);
        int right=heightBalance(root->right,depth);
        cout<<"root ->"<<root->val<<" "<<"left -> "<<left<<" "<<"right -> "<<right<<endl;
        if(abs(left-right)>1){
            cout<<"height -> "<<left<<" "<<right<<endl;
            find=false;
            return 0;
        }
        if(left>right){
            return left+1;
        }
        return right+1;
    }

    bool isBalanced(TreeNode* root) {
        heightBalance(root,0);

        return find;
    }
};