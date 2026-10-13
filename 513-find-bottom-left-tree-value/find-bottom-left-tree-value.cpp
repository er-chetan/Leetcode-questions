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
    int maxi=INT_MIN;
    int num;
    void helper(TreeNode* root,int level){
        if(root==NULL) return;
        
        if(root->left==NULL){
            if(maxi<level){
                maxi=level;
                num=root->val;
            }
        }
        if(root->left){
            if(maxi<level){
                maxi=level;
                num=root->val;
            }
            // level++;
           
        }
         helper(root->left,level+1);
        helper(root->right,level+1);
    }
    int findBottomLeftValue(TreeNode* root) {
        helper(root,1);

        cout<<maxi<<" "<<num;

        return num;


    }
};