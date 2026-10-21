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
    set<int> s;
    bool find=false;
    void helper(TreeNode* root1){
        if(root1==NULL) return ;

        helper(root1->left);
        s.insert(root1->val);
        helper(root1->right);
    }
    void match(TreeNode* root2,int target){
        if(root2==NULL) return;

        match(root2->left,target);
        if(s.find(target-root2->val)!=s.end()){
            find=true;
            return;
        }
        match(root2->right,target);

    }
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        helper(root1);
        match(root2,target);


        return find;
    }
};