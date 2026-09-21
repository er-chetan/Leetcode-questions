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
    float min=INT_MAX;
    int val=INT_MAX;
    void helper(TreeNode* root, double target){
        if(root==NULL) return;
        
        if(min>abs(root->val-target)){
            min=abs(root->val-target);
            val=root->val;
        }

        if(min==abs(root->val-target) && val>root->val) val=root->val;

        helper(root->left,target);
        helper(root->right,target);
    }
    int closestValue(TreeNode* root, double target) {
        helper(root,target);
        cout<<val<<" "<<min;

        return val;
    }
};