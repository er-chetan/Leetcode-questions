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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // l1=reverse(l1);
        // l2=reverse(l2);
        ListNode *temp1=l1,*temp2=l2;
        int len1=0,len2=0;
        while(temp1){
            len1++;
            temp1=temp1->next;
        }
        while(temp2){
            len2++;
            temp2=temp2->next;
        }
        cout<<len1<<" "<<len2;
        int carry=0,sum=0;
        ListNode *ltemp,*stemp,*store,*last;
        if(len1>len2){
            ltemp=l1;
            stemp=l2;
            store=l1;
        }else{
            ltemp=l2;
            stemp=l1;
            store=l2;
        }

        while(ltemp!=NULL && stemp!=NULL){
            sum=ltemp->val+stemp->val+carry;
            if(sum>=10){
                ltemp->val=sum%10;
                carry=sum/10;
            }else{
                ltemp->val=sum;
                carry=0;
            }
            if(ltemp->next==NULL) last=ltemp;
            ltemp=ltemp->next;
            stemp=stemp->next;
            
            // if small temp is equal to NULL //
            if(stemp==NULL && ltemp!=NULL){
                while(ltemp!=NULL){
                    sum=ltemp->val+carry;
                    if(sum>=10){
                        ltemp->val=sum%10;
                        carry=sum/10;
                    }else{
                        ltemp->val=sum;
                        carry=0;
                    }
                    if(ltemp->next==NULL) last=ltemp;
                    ltemp=ltemp->next;  
                }
            }
        }

        if(stemp==NULL && ltemp==NULL){
            if(sum>=10){
                ListNode* t=new ListNode(carry);
                last->next=t;
            }
            return store;
        }
         
        
        if(sum>=10){
            ListNode* t=new ListNode(carry);
            last->next=t;
        }

        return store;
        
    }
};