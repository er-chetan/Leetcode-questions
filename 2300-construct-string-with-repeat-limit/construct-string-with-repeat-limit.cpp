class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char,int> m;
        for(auto str : s) m[str]++;
        priority_queue<pair<char,int>> pq;
        for(auto p : m) pq.push(p);
        string res="";
        while(!pq.empty()){
            auto larg=pq.top();
            pq.pop();
            int len=min(repeatLimit,larg.second);
            for(int i=0;i<len;i++){
                res+=larg.first;
            }
            pair<char,int> seclarg;
            if(larg.second-len>0){
                if(!pq.empty()){
                    seclarg=pq.top();
                    pq.pop();
                    res+=seclarg.first;
                }else{
                    return res;
                }
                if(seclarg.second-1>0) pq.push({seclarg.first,seclarg.second-1});
                pq.push({larg.first,larg.second-len});
            }
        }

        return res;
    }
};