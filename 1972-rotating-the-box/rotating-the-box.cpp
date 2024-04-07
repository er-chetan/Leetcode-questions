class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n=box.size();
        int m=box[0].size();
        for(int i=0;i<n;i++){
            int idx=-1;
            for(int j=0;j<m;j++){
                if(box[i][j]=='*'){
                    idx=-1;
                    continue;
                }else if(box[i][j]=='.' && idx>-1){
                    swap(box[i][idx],box[i][j]);
                    idx++;
                }else if(idx==-1 && box[i][j]=='#'){
                    idx=j;
                }
            }
        }

        vector<vector<char>> res;
        for(int j=0;j<m;j++){
            vector<char> r;
            for(int i=n-1;i>=0;i--){
                r.push_back(box[i][j]);
            }
            res.push_back(r);
        }

        return  res;
    }
};