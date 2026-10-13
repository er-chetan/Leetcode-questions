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
    map<pair<int,int>,vector<int>> m;
    void helper(TreeNode* root,int row,int col){
        if(root==NULL) return;

        m[{col,row}].push_back(root->val);

        helper(root->left,row+1,col-1);
        helper(root->right,row+1,col+1);


    }

    vector<vector<int>> verticalOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        helper(root,0,0);
        int check;
        for(auto [pr,vec] : m){
            
            if(pr.first==check){
                int n=ans.size();
                ans[n-1].insert(ans[n-1].end(),vec.begin(),vec.end());
            }else{
                ans.push_back(vec);
                check=pr.first;
            }
            
        }

        return ans;
    }
};