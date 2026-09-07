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
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        ListNode* temp=head;
        ListNode* prev;
        unordered_map<int,int> m;
        while(temp!=NULL){
            m[temp->val]++;
            temp=temp->next;
        }
        bool firsthead=false;
        for (auto ele : m){
            if(ele.second==1){
                firsthead=true;
                break;
            }
        }

        if(firsthead==false) return NULL;
        int size=0;
        temp=head;
        ListNode* fh;
        while(temp!=NULL){
            if(m[temp->val]==1){
                size++;
                if(size==1){
                    fh=temp;
                    prev=fh;
                }else{
                    prev->next=temp;
                    prev=prev->next;
                }
            }
            temp=temp->next;
        }

        prev->next=NULL;

        return fh;
    }
};