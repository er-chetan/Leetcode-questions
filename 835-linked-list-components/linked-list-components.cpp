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
        unordered_map<int,ListNode*> m;
        ListNode* temp=head;
        while(temp!=NULL){
            m[temp->val]=temp->next;
            temp=temp->next;
        }
        unordered_set<int> s;
        for(auto ele : nums){
            s.insert(ele);
        }

        int count=0;
        ListNode* nex=head;
        bool find=false;
        while(s.size()>0){
            if(s.find(nex->val)!=s.end()){
                find=true;
                s.erase(nex->val);
            }else{
                if(find==true) count++;
                find=false;
            }
            nex=m[nex->val];
        }

        if(find==true){
            return count+1;
        }

        
        return count;
    }
};