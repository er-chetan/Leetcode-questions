class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        int sum=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]+1){
                sum+=nums[i];
                cout<<sum<<" ";
            }else{
                break;
            }
        }

        while(s.count(sum)){
            // cout<<sum<<" "; 
            ++sum;
        }

        return sum;
    }
};