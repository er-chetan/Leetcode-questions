class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        map<int,int> m;
        vector<vector<int>> ans;
        sort(items.begin(),items.end());
        reverse(items.begin(),items.end());
        int count=0;
        for(int i=0;i<items.size();i++){
                if(count==5 && m.find(items[i][0])!=m.end()){
                    continue;
                }

                if(m.find(items[i][0])==m.end()){
                    count=0;
                }
                
                if(m.find(items[i][0])!=m.end()){
                    m[items[i][0]]+=items[i][1];
                    count++;
                }else if(count==0 && m.find(items[i][0])==m.end()) {
                    m[items[i][0]]=items[i][1];
                    count++;    
                }

        }

        for(auto ele : m){
            ans.push_back({ele.first,ele.second/5});
        }



        return ans;
    }
};