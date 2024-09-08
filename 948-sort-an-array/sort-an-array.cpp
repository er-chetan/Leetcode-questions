class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        int j=0;
        for(auto ele : m){
            int len=ele.second;
            for(int i=0;i<len;i++){
                nums[j]=ele.first;
                j++;
            }
        }
        return nums;
    }
};