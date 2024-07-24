class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int,int> m;
        for(int i=0;i<arr.size();i++){
            m[arr[i]]=i;
        }
        vector<int> ans(arr.size(),0);
        // update the array
        int i=1;
        for(auto& ele : m){
            ele.second=i;
            i++;
        }

        for(int i=0;i<arr.size();i++){
            if(m.find(arr[i])!=m.end()){
                ans[i]=m[arr[i]];
                cout<<ans[i]<<" ";
            }
        }

        return ans;
    }
};