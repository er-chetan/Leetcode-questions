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
    vector<vector<int>> res;
    int nthlevel(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        return 1+max(nthlevel(root->left),nthlevel(root->right));
    }

    void LevelNode(TreeNode* root,int curr,int level,vector<int>& v){
        if(root==NULL){
            return;
        }
        // cout<<curr<<endl;
        if(curr==level){
            v.push_back(root->val);
        }
        curr++;
        LevelNode(root->left,curr,level,v);
        LevelNode(root->right,curr,level,v);


    }

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int itrlevel=nthlevel(root);

        for(int i=itrlevel;i>0;i--){
            vector<int> v;
            LevelNode(root,1,i,v);
            for(int j=0;j<v.size();j++){
                cout<<v[j]<<" ";
            }
            res.push_back(v);
        }
        return res;
    }
};