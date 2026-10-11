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
            // cout<<sum<<" ";
            if(m[sum].size()!=2){
                // cout<<"yes -> "<<sum<<" "<<nums[i]<<endl;
                m[sum].push_back(nums[i]);
            }else if(m[sum].size()==2){
                sort(m[sum].begin(),m[sum].end());
                if(m[sum][0]<nums[i]) m[sum][0]=nums[i];
                // cout<<sum<<"="<<m[sum][0]<<" "<<m[sum][1]<<endl;
            }

        }
        int maxi=INT_MIN;
        for(auto ele : m){
            // sort(ele.second.begin(),ele.second.end());

            if(ele.second.size()>1){
                // cout<<ele.second[0]<<" "<<ele.second[1]<<endl;
                int sum=ele.second[0]+ele.second[1];
                if(sum>maxi) maxi=sum;
            }
        }

        if(maxi!=INT_MIN) return maxi;

        return -1;
    }
};