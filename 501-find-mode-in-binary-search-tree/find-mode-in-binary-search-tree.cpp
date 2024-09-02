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
    void helper(TreeNode* root,unordered_map<int,int>& m){
        if(root==NULL) return;
        m[root->val]++;
        helper(root->left,m);
        helper(root->right,m);
    }
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int> m;
        helper(root,m);
        int  maxi=INT_MIN;
        for(auto ele : m){
            if(ele.second>maxi){
                maxi=ele.second;
            }
        }
        vector<int> v;
        for(auto ele : m){
            if(ele.second==maxi){
                v.push_back(ele.first);
            }
        }

        for(auto ele : v){
            cout<<ele<<" ";
        }


        return v;


    }
};