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
    long long count=0;
    long long helper(TreeNode* root,long long sum){
        if(root==NULL){
            return 0;
        }
        long long left=helper(root->left,sum);
        long long right=helper(root->right,sum);
        sum+=left+right;
        if(root->val==sum) count++;
        return sum+root->val;
    }
    int equalToDescendants(TreeNode* root) {
        helper(root,0);

        return count;
    }
};