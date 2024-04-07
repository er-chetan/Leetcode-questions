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

    ListNode* reverse(ListNode* head){
        ListNode *pre=NULL,*nex=head,*curr=head;
        while(nex!=NULL){
            nex=nex->next;
            curr->next=pre;
            pre=curr;
            curr=nex;
        }

        return pre;

    }
    ListNode* doubleIt(ListNode* head) {
        head=reverse(head);
        ListNode* temp=head;
        int num,rem,carry=0;
        while(temp){
            num=temp->val*2;
            if(num>9){
                num=num+carry;
                rem=num%10;
                temp->val=rem;
                carry=num/10;
            }else{
                temp->val=num+carry;
                carry=0;
            }
            if(carry!=0 && (temp->next==NULL)){
                ListNode* t=new ListNode(carry);
                temp->next=t;
                temp=temp->next;
            }

            temp=temp->next;
        }

        return reverse(head);
    }
};