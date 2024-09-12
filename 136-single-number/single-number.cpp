class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        sort(nums.begin(),nums.end());
        int freq=1;
        int single=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                freq++;
            }else{
                if(freq==1){
                    single=nums[i];
                }
                if(i==nums.size()-2 && single==0){
                    single=nums[i+1];
                }
                freq=1;
            }
        }

        cout<<single;
        return single;
    }
};