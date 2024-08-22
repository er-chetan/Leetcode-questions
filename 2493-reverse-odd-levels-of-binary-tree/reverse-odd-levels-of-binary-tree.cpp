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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level=0;
        while(q.size()>0){
            int n=q.size();
            if(level%2!=0){
                vector<int> r;
                for(int i=0;i<n;i++){
                    TreeNode* t=q.front();
                    cout<<t->val<<" "; 
                    q.pop();
                    r.push_back(t->val);
                    q.push(t);
                }     
                cout<<endl;
                for(int i=n-1;i>=0;i--){
                    TreeNode* t=q.front();
                    cout<<t->val<<" "; 
                    q.pop();
                    t->val=r[i];
                    q.push(t);
                }

            }                   
            for(int i=0;i<n;i++){
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left!=NULL){
                    q.push(temp->left);
                }
                if(temp->right!=NULL){
                    q.push(temp->right);
                }
            }
            level++;
        }

        return root;
    }
};