class Solution {
public:
    string mostCommonWord(string para, vector<string>& banned) {
        unordered_map<string,int> m;
        string s="";

        for(int i=0;i<para.size();i++){
            if(isalpha(para[i])) s+=tolower(para[i]);
            if(!isalpha(para[i]) || i==para.size()-1){
                if(s!="")  m[s]++;
                s="";
            }
        }

        for(int i=0;i<banned.size();i++){
            m.erase(banned[i]);
        }
        int maxi=INT_MIN;
        string str="";
        for(auto ele : m){
            if(ele.second>maxi){
                maxi=ele.second;
                str=ele.first;
            }
        }

        return str;
    }
};