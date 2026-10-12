class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mini=INT_MAX;
        int maxi=INT_MIN;
        int n=arrays.size();
        int maxi_idx,mini_idx;
        for(int i=0;i<n;i++){
            for(int j=0;j<arrays[i].size();j++){
                if(maxi<arrays[i][j]) {
                    maxi=arrays[i][j];
                    maxi_idx=i;
                }

                if(mini>arrays[i][j]){
                    mini=arrays[i][j];
                    mini_idx=i;
                }


            }
        }

        if(mini_idx!=maxi_idx) return abs(mini-maxi);
        int maxi1=INT_MIN,mini1=INT_MAX;
        for(int i=0;i<n;i++){
            if(i==maxi_idx) continue;
            for(int j=0;j<arrays[i].size();j++){
                if(maxi1<arrays[i][j]) maxi1=arrays[i][j];
                if(mini1>arrays[i][j]) mini1=arrays[i][j];
            }
        }

        int result=max(abs(maxi-mini1),abs(maxi1-mini));
        // cout<<result;
        return result;
    }
};