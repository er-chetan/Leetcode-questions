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
    float min;
    // int val=INT_MAX;
    priority_queue<pair<float,int>,vector<pair<float,int>>,greater<pair<float,int>>> pq;
    void helper(TreeNode* root, double target){
        if(root==NULL) return;
        
        
        min=abs(root->val-target);
        pq.push({min,root->val});
    

        helper(root->left,target);
        helper(root->right,target);
    }
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> ans;
        helper(root,target);
        while(pq.size()>0){
            cout<<pq.top().first<<" "<<pq.top().second<<endl;
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
            if(k==0) break;
        }

        

        return ans;
    }
};