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
    
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;

        queue<pair<TreeNode*,unsigned long long>>q;
        unsigned long long ans=0;
        q.push({root,1});

        while(q.size()>0){
            unsigned long long size=q.size();
            // if (size == 1){
            //     q.push({q.front().first,1});
            //     q.pop();
            // }
            
            ans = max( q.back().second - q.front().second + 1, ans);

            while(size!=0){
                auto temp=q.front();
                TreeNode* node=temp.first;
                unsigned long long idx=temp.second;
                q.pop();
                if(node->left) q.push({node->left,idx*2});
                if(node->right) q.push({node->right,idx*2+1});
                size--;
            }
        }

        return ans;
        
    }
};