class Solution {
public:
    string frequencySort(string s) {
        map<char,int> m;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto ele : m){
            pair<int,char> p;
            p.first=ele.second;
            p.second=ele.first;
            pq.push(p);
        }
        string h="";

        while(pq.size()>0){
            pair<int,char> p=pq.top();
            pq.pop();
            cout<<p.first<<" "<<p.second<<endl;
            for(int i=0;i<p.first;i++){
                h+=p.second;
            }
        }

        return h;
        
    }
};