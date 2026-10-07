class Solution {
public:
    int findMin(vector<int>& nums) {
        bool find=true;
        int i;
        for(i=0;i<nums.size()-1;i++){
            if(nums[i]<nums[i+1]){
                continue;
            }else{
                find=false;
                break;
            }
        }

        if(find==false) return nums[i+1];

        return nums[0];




    }
};