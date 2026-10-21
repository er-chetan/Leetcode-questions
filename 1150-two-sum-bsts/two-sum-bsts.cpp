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
    bool find=false;
    void match(TreeNode* root2,int val,int target){
        if(root2==NULL) return;

        if(target-val==root2->val){
            find=true;
            return ;
        }
        else if(target-val<root2->val){
           match(root2->left,val,target);
        }else{
            match(root2->right,val,target);
        }

    }
    void helper(TreeNode* root2, TreeNode* root1, int target){
        if(root1==NULL) return;
        match(root2,root1->val,target);
        helper(root2,root1->left,target);
        helper(root2,root1->right,target);
    }
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
       
       helper(root2,root1,target);


        return  find;

    }
};