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
    TreeNode* temp;
    int maxdep=INT_MIN;
    int helper(TreeNode* root,int depth){
        if(root==NULL) return depth;
        depth++;
        int left = helper(root->left,depth);
        int right=helper(root->right,depth);
        cout<<root->val<<"="<<left<<" "<<right<<endl;
        if(left==right && depth<left){
            if(maxdep<=left){
                temp=root;
                maxdep=left;
            } 
        }else if(left>right  && maxdep<left){
            maxdep=left;
            temp=root->left;
        }else if(left<right && maxdep<right){
            maxdep=right;
            temp=root->right;
        } 
        return max(left,right);
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
       int res= helper(root,0);
       if(res==1){
        return root;
       }
    //    cout<<"last->"<<temp->val;
       return temp;
    }
};