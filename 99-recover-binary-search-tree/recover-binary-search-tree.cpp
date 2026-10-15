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
    vector<pair<int,TreeNode*>> ans;
    void helper(TreeNode* root){
        if(root==NULL) return;
        
        helper(root->left);
        ans.push_back({root->val,root});
        helper(root->right);
    }

    void display(vector<pair<int,TreeNode*>> ans){

        int idx=-1;

        TreeNode* first_dec=NULL;
        TreeNode* first_inc=NULL;
        int i=0,n=ans.size();
        for(i=0;i<n-1;i++){
            if(ans[i].first>ans[i+1].first){
                first_dec=ans[i].second;
                idx=i;
                break;
            }
        }

        // cout<<i<<endl;
        
        for(int j=i+1;j<n-1;j++){
            if(ans[j].first>ans[j+1].first){
                first_inc=ans[j+1].second;
                break;
            }
        }

        

        int num=first_dec->val;
        if(first_inc==NULL){
            first_inc=ans[idx+1].second;
        }
        
        first_dec->val=first_inc->val;
        first_inc->val=num;


        return;
    }
    
    void recoverTree(TreeNode* root) {
        helper(root);
        display(ans);
        return ;
    }

    
};