class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(int('a')<=int(s[i]) && int('z')>=int(s[i])){
                cout<<"y"<<" ";
                st.push(s[i]);
            }

            if(s[i]-'0'>=0 && s[i]-'0'<=9){
                cout<<"n"<<" ";
                st.pop();
            }
            
        }
        string ans="";
        while(st.size()>0){
            ans+=st.top();
            st.pop();
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};