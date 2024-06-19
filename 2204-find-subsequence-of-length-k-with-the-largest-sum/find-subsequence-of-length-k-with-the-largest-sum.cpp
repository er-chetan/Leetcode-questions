class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i],i});
            if(pq.size()>k){
                pq.pop();
            }
        }
        
        map<int,int> m;

        while(pq.size()>0){
            m[pq.top().second]=pq.top().first;
            pq.pop();
        }

        vector<int> ans;
        for(auto ele : m){
            ans.push_back(ele.second);
        }

        return ans;
    }
};