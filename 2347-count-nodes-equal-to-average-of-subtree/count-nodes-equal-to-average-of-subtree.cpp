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
    int count=0;

    // int freq=0;
    
    pair<int,int> helper(TreeNode* root,int sum,int freq){
        if(root==NULL) return {sum,freq};
        
        pair<int,int>leftsum=helper(root->left,sum,freq);
        pair<int,int>rightsum=helper(root->right,sum,freq);
        freq++;
        sum+=root->val;
        int totalfreq=freq+leftsum.second+rightsum.second;
        int avrg=(sum+leftsum.first+rightsum.first)/totalfreq;
        if(avrg==root->val) count++;
        return {sum+leftsum.first+rightsum.first,totalfreq};
    }
    int averageOfSubtree(TreeNode* root) {
        if(root==NULL) return 0;
        pair<int,int> r= helper(root,0,0);
        return  count;

    }
};