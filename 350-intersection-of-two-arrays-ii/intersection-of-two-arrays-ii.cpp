class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m,n;
        vector<int> v;
        for(int i=0;i<nums1.size();i++) m[nums1[i]]++;
        for(int i=0;i<nums2.size();i++) n[nums2[i]]++;
        for(auto ele : m){
            if(n.find(ele.first)!=n.end()){
                if(ele.second==n[ele.first]){
                    while(ele.second>0){
                        v.push_back(ele.first);
                        ele.second--;
                    }
                }else if(ele.second>n[ele.first]){
                    while(n[ele.first]>0){
                        v.push_back(ele.first);
                        n[ele.first]--;
                    }
                }else if(ele.second<n[ele.first]){
                    while(ele.second>0){
                        v.push_back(ele.first);
                        ele.second--;
                    }
                }
            }
        }
        return v;
    }
};