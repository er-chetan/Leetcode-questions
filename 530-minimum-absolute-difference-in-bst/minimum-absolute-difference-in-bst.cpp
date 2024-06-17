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
    vector<int> ans;

    void inorder(TreeNode* root){
        if(root==NULL) return;
        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);
}
     
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        int diff=INT_MAX;
        for(int i=0;i<ans.size()-1;i++){
            if(diff>abs(ans[i]-ans[i+1])){
                diff=abs(ans[i]-ans[i+1]);
            }
        }
        return diff;
    }
};