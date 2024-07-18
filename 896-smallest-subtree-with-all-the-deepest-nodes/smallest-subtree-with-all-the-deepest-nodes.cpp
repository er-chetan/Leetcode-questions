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
    TreeNode* ans=NULL;
    int level=0;
    int helper(TreeNode* root,int depth){
        if(root==NULL){
            return depth;
        }
        depth++;
        int left=helper(root->left,depth);
        int right=helper(root->right,depth);
        cout<<"value->"<<root->val<<" "<<"depth ->"<<depth<<" "<<left<<" "<<right<<endl;

        if((left==right ) && level<=left){
            ans=root;
            level=left;
            cout<<ans->val<<" ";
        }
        if(left>right){
            return left;
        }
        return right;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int res=helper(root,0);

        // cout<<ans->val;
        return ans;
    }
};