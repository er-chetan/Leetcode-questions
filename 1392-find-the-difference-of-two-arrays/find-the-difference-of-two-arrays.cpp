class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> p,q;
        for(auto ele : nums1) p.insert(ele);
        for(auto ele : nums2) q.insert(ele);

        vector<int> first,second;
        for(auto ele : p){
            if(q.find(ele)==q.end())  first.push_back(ele); 
        }
        for(auto ele : q){
            if(p.find(ele)==p.end())  second.push_back(ele); 
        }
        vector<vector<int>> ans={first,second};
        // ans.push_back(first);
        // ans.push_back(second);
        return ans;
    }
};