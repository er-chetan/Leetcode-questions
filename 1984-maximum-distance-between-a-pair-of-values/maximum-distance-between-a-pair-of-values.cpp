class Solution {
public:

    int search(vector<int>& nums2,int lo,int num){
        int hi=nums2.size()-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(nums2[mid]>=num) lo=mid+1;
            else hi=mid-1;
        }

        return hi;
    }
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int maxi=0;
        for(int i=0;i<n;i++){
            int res=search(nums2,i,nums1[i]);
            if(maxi<(res-i)) maxi=res-i;
        }


        return maxi;
    }
};