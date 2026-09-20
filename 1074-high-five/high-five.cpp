class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        map<int,int> m;
        vector<vector<int>> ans;
        sort(items.begin(),items.end());
        reverse(items.begin(),items.end());
        // int num=-1;
        // int sum=0;
        int count=0;
        // int num_prev=-1
        for(int i=0;i<items.size();i++){
                // cout<<count<<" ";
                if(count==5 && m.find(items[i][0])!=m.end()){
                    // cout<<"y"<<" ";
                    // count=0;
                    continue;
                }

                if(m.find(items[i][0])==m.end()){
                    count=0;
                }
                
                if(m.find(items[i][0])!=m.end()){
                    m[items[i][0]]+=items[i][1];
                    cout<<m[items[i][0]]<<" "<<items[i][0]<<endl;
                    count++;
                }else if(count==0 && m.find(items[i][0])==m.end()) {
                    m[items[i][0]]=items[i][1];
                    cout<<m[items[i][0]]<<" "<<items[i][0]<<endl;
                    count++;    
                }

        }

        for(auto ele : m){
            // cout<<ele.first<<" "<<ele.second<<endl;
            ans.push_back({ele.first,ele.second/5});
        }



        return ans;
    }
};