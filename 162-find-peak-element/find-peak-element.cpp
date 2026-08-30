class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int next=INT_MIN;
        int next_ind=-1;
        for(int i=0;i<nums.size();i++){
            if(next<=nums[i]){
                next=nums[i];
                next_ind=i;
                // cout<<next<<"="<<i<<endl;
            }
        }



        return next_ind;
    }
};