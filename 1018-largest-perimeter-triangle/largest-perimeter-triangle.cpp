class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.rbegin(),nums.rend());
        for(int i=0;i<nums.size()-2;i++){
            cout<<nums[i]+nums[i+1]+nums[i+2]<<endl;
            if(nums[i]<nums[i+1]+nums[i+2]){
                return nums[i]+nums[i+1]+nums[i+2];
            }
        }

        return 0;
    }
};