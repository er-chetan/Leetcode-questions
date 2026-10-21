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
    int height(TreeNode* root){
        if (root==NULL) return 0;

        return 1+max(height(root->left),height(root->right));
    }
    vector<vector<string>> printTree(TreeNode* root) {
        int h=height(root)-1;

        int m=h+1;
        int n=pow(2,h+1)-1;

        vector<vector<string>> ans(m, vector<string>(n,""));
        queue<pair<TreeNode*,pair<int,int>>> q;

        q.push({root,{0,(n-1)/2}});
        ans[0][(n-1)/2]=to_string(root->val);
        while(q.size()>0){
            auto it=q.front();
            TreeNode* temp=it.first;
            int row=it.second.first;
            int col=it.second.second;
            q.pop();

            if(temp->left){
                ans[row+1][col-pow(2,h-row-1)]=to_string(temp->left->val);
                q.push({temp->left,{row+1,col-pow(2,h-row-1)}});
            }

            if(temp->right){
                ans[row+1][col+pow(2,h-row-1)]=to_string(temp->right->val);
                q.push({temp->right,{row+1,col+pow(2,h-row-1)}});
            }
        }

    


        return ans;
    }
};