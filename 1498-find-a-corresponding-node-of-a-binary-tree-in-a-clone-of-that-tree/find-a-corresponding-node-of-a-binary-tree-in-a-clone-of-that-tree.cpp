/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* ref=NULL;
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(original==NULL) return NULL;

        if(original==target) ref=cloned;
        getTargetCopy(original->left,cloned->left,target);
        getTargetCopy(original->right,cloned->right,target);
        return ref;
    }
};