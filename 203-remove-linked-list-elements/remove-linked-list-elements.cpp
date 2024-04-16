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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* temp=head;
        ListNode* fake=new ListNode(-1);
        ListNode* f=fake;
        while(temp!=NULL){
            if(temp->val!=val){
                f->next=temp;
                f=f->next;
            }
            temp=temp->next;
        }
        f->next=NULL;
        return fake->next;
    }
};