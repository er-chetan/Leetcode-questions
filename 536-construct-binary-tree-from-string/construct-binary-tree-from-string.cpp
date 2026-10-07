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
    
    TreeNode* str2tree(string s) {
        stack<TreeNode*> nod;
        if(s=="") return NULL; 
        int i=0;
        string str="";
        while(i<s.size()){

            if(isdigit(s[i]) || s[i]=='-'){
                str=str+s[i];
            }else if(str!=""){
                // int num=stoi(str);
                TreeNode* temp=new TreeNode(stoi(str));
                nod.push(temp);
                str="";
            }
            
            if(nod.size()>1 && s[i]==')'){
                TreeNode* child=nod.top();
                nod.pop();
                TreeNode* parent=nod.top();
                if(parent->left==NULL){
                    parent->left=child;
                }else{
                    parent->right=child;
                 }
            }
            i++;
        }

        if(str!=""){ 
            // int num=stoi(str);
            TreeNode* temp=new TreeNode(stoi(str));
            nod.push(temp);
        }
        
        return nod.top();
    }
};