class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs.size();
        int count=0;
        int m=strs[0].size();
        for(int i=0;i<m;i++){
            int ascii=0;
            int mini=0;
            for(int j=0;j<n;j++){
                ascii=int(strs[j][i]);
                // cout<<ascii<<"="<<strs[j][i]<<endl;
                if(ascii>=mini){
                    mini=ascii;
                }else{
                    // cout<<"yes";
                    count++;
                    break;
                }
            }
        }


        return count;
    }
};