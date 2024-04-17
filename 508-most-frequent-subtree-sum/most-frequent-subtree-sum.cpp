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
    int  helper(TreeNode* root,int sum,unordered_map<int,int>& m){
        if(root==NULL){
            return 0;
        }
        if(root->left==NULL && root->right==NULL){
            sum+=root->val;
            m[root->val]++;
            return sum;
        }
        int lsum=helper(root->left,sum,m);
        int rsum=helper(root->right,sum,m);
        sum=root->val+lsum+rsum;
        m[sum]++;
        return sum;
        
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> v;
        unordered_map<int,int> m;
        int sum=0;
        helper(root,sum,m);
        int maxi=INT_MIN;
        for(auto ele : m){
            if(maxi<ele.second){
                maxi=ele.second;
            }
        }

        for(auto ele : m){
            if(maxi==ele.second){
                v.push_back(ele.first);
            }
        }

        return v;

    }
};