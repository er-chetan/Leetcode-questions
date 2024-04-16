class Solution {
public:
    bool backspaceCompare(string s, string g) {
        int count=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='#'){
                s[i]='.';
                count++;
            }
            else if(count>0  && s[i]!='#'){
                count--;
                s[i]='.';
            }
        }
        count=0;
        for(int i=g.size()-1;i>=0;i--){
            if(g[i]=='#'){
                g[i]='.';
                count++;
            }
            else if(count>0 && g[i]!='#'){
                count--;
                g[i]='.';
            }
        }
        
        s.erase(remove(s.begin(), s.end(), '.'), s.end());
        g.erase(remove(g.begin(), g.end(), '.'), g.end());
        cout<<s<<"     "<<g;
        if(s!=g ) return false;
        return true;
    }
};