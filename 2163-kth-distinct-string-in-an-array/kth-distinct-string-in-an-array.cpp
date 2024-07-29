class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> ans;
        for(int i=0;i<arr.size();i++){
            ans[arr[i]]++;
        }
        for(int i=0;i<arr.size();i++){
            if(ans[arr[i]]==1){
                k--;
            }
            if(k==0){
                return arr[i];
            }
        }



        return "";
    }
};