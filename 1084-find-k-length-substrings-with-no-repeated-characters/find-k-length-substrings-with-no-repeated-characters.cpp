class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        unordered_map<char,int> m;
        if(s.size()<k) return 0;
        for(int i=0;i<k;i++){
            m[s[i]]++;
        }
        
        int j=0;
        int count=0;
        if(m.size()==k){
            // cout<<"y";
            count++;
        }
        for(int i=k;i<s.size();i++,j++){
            m[s[j]]--;
            if(m[s[j]]==0) m.erase(s[j]);
            // if(m.find(s[i])!=m.end()){
                m[s[i]]++;
            // }

            if(m.size()==k && m[s[i]]==1){
                // cout<<s[i]<<" "<<m.size()<<endl;
                count++;
            }
        }

        // cout<<count;

        return count;
    }
};