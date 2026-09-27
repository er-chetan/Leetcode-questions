class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum=0;
        double maxi=INT_MIN;
        double avrg=0.0;
        for(int i=0;i<k;i++){
            sum=sum+nums[i];
        }
        maxi=sum/k;
        int j=0;
        for(int i=k;i<nums.size();i++,j++){
            sum=sum-nums[j]+nums[i];
            avrg=sum/k;
            cout<<avrg<<" ";
            if(avrg>maxi){
                maxi=avrg;
            }
        }

        // cout<<prev_avrg<<" "<<avrg;

        return maxi;
    }
};