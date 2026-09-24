class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int i=0;
        for(i=0;i<nums.size();i++){
            int sum=0;
            int n=nums[i];
            while(n>0){
                sum=sum+(n%10);
                n=n/10;
            }
            if(i==sum){
                return i;
            }
        }
        return -1;
    }
       
};