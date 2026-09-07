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
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        ListNode* temp=head;
        int m1=m;
        int n1=n;
        ListNode* connect;
        while(temp!=NULL){
            if(m1!=0){
                m1--;
                connect=temp;
                // if(m1==0)
            }else if(m1==0){
                connect->next= NULL;
                if(n1!=0){
                    n1--;
                    if(n1==0){
                        n1=n;
                        m1=m;
                        if(temp!=NULL && connect!=NULL){
                            connect->next=temp->next;
                            // cout<<temp->next->val;
                        }
                    }
                }
            }
            temp=temp->next;
        }

        return head;
    }
};