class Solution {
public:
    vector<int> topStudents(vector<string>& p, vector<string>& n, vector<string>& report, vector<int>& id, int k) {
        unordered_map<string, int>pos, neg;
        for(int i=0; i<p.size(); i++){
            pos[p[i]]++;
        }
        for(int i=0; i<n.size(); i++){
            neg[n[i]]++;
        }
        priority_queue<pair<int, int>>v;
        for(int i=0; i<id.size(); i++){
            int cnt=0;
            stringstream s(report[i]);
            while(getline(s, report[i], ' ')){
                //cout<<report[i]<<endl;
                if(pos.find(report[i])!=pos.end()){
                    cnt+=3;
                }
                if(neg.find(report[i])!=neg.end()){
                    cnt--;
                }
            }
            v.push({cnt, id[i]});
        }
        vector<int>ans;
        int prev=-1, cnt=0;
        while(!v.empty()){
            if(prev==v.top().first){
                cnt++;
            }
            else{
                cnt=0;
            }
            prev=v.top().first;
            if(ans.empty()){ans.push_back(v.top().second);}
            else{
                ans.insert(ans.begin()+ans.size()-cnt, v.top().second);
            }
            v.pop();
        }
        vector<int>a;
        for(int i=0; i<k; i++){
            a.push_back(ans[i]);
        }
        return a;
    }
};