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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level=0;
        while(q.size()>0){
            int n=q.size();
            int prev=q.front()->val;
            for(int i=0;i<n;i++){
                TreeNode* temp=q.front();
                if(level%2==0 && temp->val%2==0){
                    return false;
                }
                if(level%2!=0 && temp->val%2!=0){
                    return false;
                }
                q.pop();
                // prev=temp->val;
                if(level%2==0 && level>0){
                    cout<<"even"<<" ";
                    if(prev>=temp->val && i!=0){
                        return false;
                    }else{
                        prev=temp->val;
                    }
                }
                if(level%2!=0 && level>0){
                    cout<<"odd"<<" ";
                    if(prev<=temp->val && i!=0){
                        return false;
                    }else{
                        prev=temp->val;
                    }
                }
                if(temp->left!=NULL){
                    q.push(temp->left);
                }
                if(temp->right!=NULL){
                    q.push(temp->right);
                }
            }
            level++;

        }
        
        return true;
    }
};