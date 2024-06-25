class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        map<int,char> m;
        for(int i=0;i<s.size();i++){
            m[indices[i]]=s[i];
        }
        string str="";
        for(auto ele : m){
            str+=ele.second;
        }
        return str;
    }
};