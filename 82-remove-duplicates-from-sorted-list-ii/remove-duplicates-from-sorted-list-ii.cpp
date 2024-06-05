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
    ListNode* deleteDuplicates(ListNode* head) {
        map<int,int> m;
        ListNode* temp=head;
        while(temp){
            m[temp->val]++;
            temp=temp->next;
        }
        ListNode* fake=new ListNode(-1);
        temp=fake;
        for(auto ele : m){
            if(ele.second==1){
                ListNode* New=new ListNode(ele.first);
                temp->next=New;
                temp=temp->next;
            }
        }

        return fake->next;

    }
};