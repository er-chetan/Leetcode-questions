class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int height=0;
        vector<int> ans;
        for(int i=1;i<label;i++){
            if(label>=pow(2,i)){
                height++;
            }
        }
        // cout<<height<<" h";
        // h--
        ans.push_back(label);
        while(height){
            int mini_value=pow(2,height-1);// previous level
            int maxi_value=pow(2,height)-1;// previous level
            label=mini_value+maxi_value-(label/2);
            // cout<<label<<" ";
            ans.push_back(label);
            height--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};