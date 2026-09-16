class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> v(length,0);

        for(int i=0;i<updates.size();i++){
            int st=updates[i][0];
            int end=updates[i][1];
            int inc=updates[i][2];
            for(int j=st;j<=end;j++){
                v[j]=v[j]+inc;
            }
        }

        for(auto ele :v){
            cout<<ele<<" ";
        }

        return v;
    }
};