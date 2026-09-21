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
    unordered_map<int,int> m;

    

    ListNode* frequenciesOfElements(ListNode* head) {
        ListNode* temp=head;

        while(temp!=NULL){
            m[temp->val]++;
            temp=temp->next;
        }

        ListNode* newhead=NULL;

        for(auto ele : m){
            cout<<ele.first<<" "<<ele.second<<endl;
            ListNode* newnode=new ListNode(ele.second);
            if(newhead==NULL){
                newhead=newnode;
                temp=newnode;
            }else{
                temp->next=newnode;
                temp=temp->next;
            }
        }

        temp=newhead;

        while(temp!=NULL){
            // cout<<temp->val<<" ";
            temp=temp->next;
        }

        return newhead;
    }
};