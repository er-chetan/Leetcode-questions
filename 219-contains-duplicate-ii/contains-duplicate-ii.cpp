class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int n=nums.size();
         
        for(int i=0;i<n;i++){
            if(m.find(nums[i])!=m.end() ){
                cout<<m[nums[i]]-i<<" ";
                if(abs(m[nums[i]]-i)<=k) return true;
            }
            m[nums[i]]=i;
        }

        return false;
    }
};