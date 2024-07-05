class Solution {
public:
    bool answer(vector<int>&nums,int mid, int k){
       // cout<<mid<<endl;
        int sum=0;
        int j=1;
        for(int i=0; i<nums.size(); i++){
            while(j<nums.size()&&nums[j]-nums[i]<=mid)
                j++;
            j--;
            sum+=j-i;
        }
        if(sum>=k)
            return true;
        return false;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int l=0;
        int r=nums[nums.size()-1]-nums[0];
        int ans;
        while(l<=r){
            int mid=r-(r-l)/2;
            if(answer(nums,mid,k)){
                ans=mid;
                 r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};