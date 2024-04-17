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
    void helper(TreeNode* root,vector<int>& v,int s){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            s=s*10+root->val;
            v.push_back(s);
            return;
        }
        s=s*10+root->val;
        helper(root->left,v,s);
        helper(root->right,v,s);
    }
    int sumNumbers(TreeNode* root) {
        int s=0;
        vector<int> v;
        helper(root,v,s);
        int sum=0;
        for(auto ele : v){
            sum+=ele;
        }

        return sum;
    }
};