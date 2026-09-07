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
        // cout<<"start"<<endl;
        ListNode* fh;
        while(temp!=NULL){
            // cout<<temp->val<<" ";
            if(m[temp->val]==1){
                size++;
                if(size==1){
                    fh=temp;
                    prev=fh;
                    // prev->next=NULL;
                    // cout<<prev->val;
                }else{
                    // cout<<prev->val;
                    prev->next=temp;
                    prev=prev->next;
                    // cout<<prev->val;
                    // prev->next=NULL;
                }
            }
            temp=temp->next;
        }

        prev->next=NULL;

        return fh;
    }
};