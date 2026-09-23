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
    int sum=0;
    int total=0;
    int helper(TreeNode* root,int left,int right){
        if(root==NULL){
            return 0;
        }
        int L=helper(root->left,left,right);
        int R=helper(root->right,left,right);
        // total=total+L+R;
        sum=sum+abs(L-R);
        // cout<<L<<" "<<R<<" "<<sum<<endl;
        
        return root->val+L+R;
    }
    int findTilt(TreeNode* root) {
        helper(root,0,0);
        cout<<sum;
        return sum;
    }
};