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
    int numComponents(ListNode* head, vector<int>& nums) {
        int c=0;
        ListNode* temp=head;
        unordered_map<int,int> mp;

        for(auto i:nums){
            mp[i]++;
        }
         
         while(temp!=NULL){
            if(mp.find(temp->val)!=mp.end()){
                 if(temp->next){
                    if(mp.find(temp->next->val)==mp.end()){
                       c++;
                    }
                }else{
                   c++;
                }
            }
             temp=temp->next;
       }

        return c;
    }
};