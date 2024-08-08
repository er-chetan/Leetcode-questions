class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        map<char,int>m,m2;
        for(int i=0;i<s.size();i++){
            if(m.find(s[i])==m.end()){
                m[s[i]]=i;
            }else{
                m[s[i]]=i-m[s[i]]-1;
            }
        }

        for(int i=0;i<distance.size();i++){
            m2[char(97+i)]=distance[i];
        }

        for(auto ele : m){
            if(m2.find(ele.first)!=m2.end()){
                if(ele.second!=m2[ele.first]){
                    return false;
                }
            }
        }


        return true;
    }
};