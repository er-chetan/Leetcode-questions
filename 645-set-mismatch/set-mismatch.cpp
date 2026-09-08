class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int,int> m;
        int max=INT_MIN;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
            if(nums[i]>max){
                max=nums[i];
            }
        }

    // cout<<"max:"<<max<<endl;
        vector<int> v;
        int value;
        for(auto ele : m){
            if(ele.second!=1){
                value=ele.first;
                cout<<"yes";
                v.push_back(ele.first);
                break;
            }
        }

        for(int i=1;i<value;i++){
            if(m.find(i)==m.end()){
                v.push_back(i);
                break;
            }
        }

        

        for(int i=value+1;i<=max;i++){
            if(m.find(i)==m.end()){
                v.push_back(i);
            }
        }

        if(v[0]==1 && v.size()==1){
            v.push_back(2);
        }

        if(v.size()==1){
            v.push_back(max+1);
        }
        



        return v;
    }
};