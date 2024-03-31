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
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode* temp=head;
        string s="";
        while(temp!=NULL){
            s=s+to_string(temp->val);
            temp=temp->next;
        }

        int num,base=1;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='1') num+=base;
            base*=2;
        }

        return num;
    }
};