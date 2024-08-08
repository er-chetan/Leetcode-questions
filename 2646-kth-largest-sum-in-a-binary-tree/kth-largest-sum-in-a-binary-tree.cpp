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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*> q;
        q.push(root);
        // long long maxi=INT_MIN;
        int level = 0;
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        while(q.size()>0){
            int n=q.size();
            long long sum=0;
            for(int i=0;i<n;i++){
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left!=NULL){
                    q.push(temp->left);
                }
                if(temp->right!=NULL){
                    q.push(temp->right);
                }
                sum+=temp->val;
                
            }
            cout<<sum<<" ";
            pq.push(sum);
            if(pq.size()>k){
                pq.pop();
            }

            level++;
        }

        if(level<k) return -1;

        return pq.top();
    }
};