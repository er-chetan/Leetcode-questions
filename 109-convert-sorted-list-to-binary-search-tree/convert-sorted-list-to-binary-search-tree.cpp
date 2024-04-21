/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* BST(vector<int>& v,int lo,int hi){
        if(lo>hi) return NULL;
        int mid=lo+(hi-lo)/2;
        TreeNode* root=new TreeNode(v[mid]);
        root->left=BST(v,lo,mid-1);
        root->right=BST(v,mid+1,hi);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> v;
        ListNode* temp=head;
        while(temp!=NULL){
            v.push_back(temp->val);
            temp=temp->next;
        }

        TreeNode* root=BST(v,0,v.size()-1); 

        return root;
    }
};