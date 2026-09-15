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
            cout<<pr.first<<" "<<pr.second<<" -> "<<check<<" "<<i<<" ";
            if(vec.size()>0){
                sort(vec.begin(),vec.end());
            }

            for(auto ele : vec){
                cout<<ele<<" ";
            }
            if(check==pr.first){
                cout<<"yes";
                for(int r=0;r<vec.size();r++){
                    res[i-1].push_back(vec[r]);
                }
            }else{
                res.push_back(vec);
                check=pr.first;
                i++;
            }

            cout<<endl;
            
        }

        cout<<"check result vector --:"<<endl;

        // for(int i=0;i<res.size();i++){
        //     for(int j=0;i<res[0].size();j++){
        //         cout<<res[i][j]<<" ";
        //     }
        // }
        return res;
    }
};