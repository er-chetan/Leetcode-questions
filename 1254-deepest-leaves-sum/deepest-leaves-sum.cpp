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
    int sum=0;
    int lastlevel(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(lastlevel(root->left),lastlevel(root->right));
    }
    void lastsum(TreeNode* root,int level,int depth){
        if(root==NULL) return;
        if(level==depth-1){
            sum+=root->val;
        }
        level++;
        lastsum(root->left,level,depth);
        lastsum(root->right,level,depth);
    }
    int deepestLeavesSum(TreeNode* root) {
        int depth=lastlevel(root);
        lastsum(root,0,depth);
        cout<<sum;
        return sum;
    }
};