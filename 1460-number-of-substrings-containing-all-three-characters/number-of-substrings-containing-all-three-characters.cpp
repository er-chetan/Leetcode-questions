class Solution {
public:
    int numberOfSubstrings(string s) {
        int i=0,j=0,ans=0;
        unordered_map<char,int> m;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
            while(m.size()==3 && i>=j){
                m[s[j]]--;
                if(m[s[j]]==0) m.erase(s[j]);
                ans+=(s.size()-i);
                j++;
            }
        }

        return ans;
    }
};