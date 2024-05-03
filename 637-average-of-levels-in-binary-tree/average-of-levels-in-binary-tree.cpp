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
    int level(TreeNode* root){
        if(root==NULL) return 0;
        return 1+(max(level(root->left),level(root->right)));
    }
    double levelsum(TreeNode* root,int curr,int level,double& count,double& sum){
        if(root==NULL) return 0;
        if(curr==level){
            sum+=root->val;
            cout<<sum<<"level"<<level<<" ";
            count++;
        }
        level++;
        levelsum(root->left,curr,level,count,sum);
        levelsum(root->right,curr,level,count,sum);
        return sum;
    }
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> v;
        
        int n=level(root);
        for(int i=0;i<n;i++){
            double count=0;
            double s=0;
            double sum=levelsum(root,i,0,count,s);
            double lsum=sum/count;
            v.push_back(lsum);
        }

        return v;
    }
};