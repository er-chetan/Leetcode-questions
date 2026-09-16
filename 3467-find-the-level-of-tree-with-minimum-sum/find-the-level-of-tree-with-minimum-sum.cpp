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
    // long long sum;
    vector<long long> ans;
    // int level(TreeNode* root){
    //     if(root==NULL) return 0;

    //     return 1+max(level(root->left),level(root->right));
    // }
    void helper(TreeNode* root,int level){
        if(root==NULL){
            return;
        }

        if(ans.size()==level){
            ans.push_back(root->val);
        }else{
            ans[level]+=root->val;
        }
        // curr++;
        helper(root->left,level+1);
        helper(root->right,level+1);

    }
    int minimumLevel(TreeNode* root) {
        int mini=INT_MAX;
        helper(root,0);
        int lev=0;
        for(int i=0;i<ans.size();i++){
            if(ans[i]<mini){
                mini=ans[i];
                lev=i+1;
            }
            cout<<lev<<" ";
        }

        // cout<<lev;

        return lev;
    }
};