class Solution {
public:
    void store_digit_string(vector<pair<char,string>>& v){
        v.push_back({'z',"zero0"});
        v.push_back({'w',"two2"});
        v.push_back({'u',"four4"});
        v.push_back({'x',"six6"});
        v.push_back({'o',"one1"});
        v.push_back({'r',"three3"});
        v.push_back({'f',"five5"});
        v.push_back({'s',"seven7"});
        v.push_back({'h',"eight8"});
        v.push_back({'i',"nine9"});
    }
    string originalDigits(string s) {
        unordered_map<char,int> m;
        for(auto ele : s) m[ele]++;
        vector<pair<char,string>> v;
        string ans="";
        store_digit_string(v);
        for(int i=0;i<v.size();i++){
            char ch=v[i].first;
            string str=v[i].second;
            if(m.find(ch)!=m.end()){
                // cout<<"size -> "<<m[ch]<<endl;
                int size=m[ch];
                for(int i=0;i<size;i++){
                    cout<<i<<" = i"<<endl;
                    for(int i=0;i<str.size()-1;i++){
                        if(m.find(str[i])!=m.end()){
                            // cout<<str[i]<<" ";
                            m[str[i]]--;
                            if(m[str[i]]==0){  
                                m.erase(str[i]);
                            }
                        }
                    }
                    ans=ans+str[str.size()-1];
                }
            }
        }
        vector<int> g;
        for(auto ele : ans) g.push_back(ele-'0');
        sort(g.begin(),g.end());
        ans="";
        for(auto ele : g) ans+=to_string(ele);


        return ans;
    }
};