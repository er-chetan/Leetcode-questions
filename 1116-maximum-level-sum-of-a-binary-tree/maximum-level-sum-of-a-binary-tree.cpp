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
    int maxLevelSum(TreeNode* root) {
        if(root==NULL || (root->left==NULL && root->right==NULL)) return 1;
        queue<TreeNode*> q;
        q.push(root);
        int level=1;
        int maxsum=root->val;
        int MLS=1;
        while(q.size()>0){
            int n=q.size();
            int sum=0;
            bool find=false;
            for(int i=0;i<n;i++){
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left!=NULL){
                    sum+=temp->left->val;
                    find=true;
                    // cout<<temp->left->val<<" ";
                    q.push(temp->left);
                }
                if(temp->right!=NULL){
                    sum+=temp->right->val;
                    find=true;
                    // cout<<temp->right->val<<" ";
                    q.push(temp->right);
                }
                
            }
            
            level++;
            if(sum>maxsum && find==true){
                maxsum=sum;
                MLS=level;
                cout<<MLS<<" = "<<"level"<<" "<<maxsum<<" = maxsum"<<endl;
            }
            
        }

        return MLS;

    }
};