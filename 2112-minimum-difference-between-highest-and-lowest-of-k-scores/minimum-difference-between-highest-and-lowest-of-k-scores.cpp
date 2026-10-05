class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int mini=INT_MAX,maxi=INT_MIN;
        sort(nums.begin(),nums.end());
        for(int i=0;i<k;i++){
            if(maxi<nums[i]) maxi=nums[i]; 
            if(mini>nums[i]) mini=nums[i];
        }

        int min_val=maxi-mini;

        int j=1;

        for(int i=k;i<nums.size();i++,j++){
            maxi=nums[i];
            mini=nums[j];
            if(maxi-mini<min_val) min_val=maxi-mini;
            
        }

        return min_val;
    }
};