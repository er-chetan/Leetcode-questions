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
        if(root==NULL){
            return;
        }
        
        m[{col,row}].push_back(root->val);

        helper(root->left,row+1,col-1);
        helper(root->right,row+1,col+1);

    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        vector<vector<int>> res;

        helper(root,0,0);

        int check=INT_MIN,i=0;
        for(auto [pr,vec] : m){
            if(vec.size()>0){
                sort(vec.begin(),vec.end());
            }

            if(check==pr.first){
                // for(int r=0;r<vec.size();r++){
                //     res[i-1].push_back(vec[r]);
                // }
                // use this instead of loop in 2d vector particular vector push back values of another vectot // we can say that push bacck whole vector in inner particular vector
                res[i-1].insert(res[i-1].end(),vec.begin(),vec.end());
            }else{
                
                res.push_back(vec);
                check=pr.first;
                i++;
            }
        }
        return res;
    }
};