class Solution {
public:
    int maximumSum(vector<int>& nums) {
        map<int,vector<int>> m;
        for(int i=0;i<nums.size();i++){
            int num=nums[i];
            int sum=0;
            while(num > 0){
                sum+=(num%10);
                num=num/10;
            }

            // if(m.find(sum)==m.end()){
                // m[sum].push_back(nums[i]);
            // }else{
                m[sum].push_back(nums[i]);
            // }
        }
        int maxi=INT_MIN;
        for(auto ele : m){
            sort(ele.second.begin(),ele.second.end());

            if(ele.second.size()>1){
                int n=ele.second.size();
                int sum=ele.second[n-1]+ele.second[n-2];
                if(sum>maxi) maxi=sum;
            }
        }

        if(maxi!=INT_MIN) return maxi;

        return -1;
    }
};