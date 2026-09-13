class Solution {
public:
    void reverseWords(vector<char>& s) {
        stack<char> st;
        vector<char> ans(s.size(),' ');
        int j=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]!=' '){
                st.push(s[i]);
            }else{
                while(st.size()>0){
                    char str=st.top();
                    // cout<<str<<" ";
                    st.pop();
                    ans[j]=str;
                    j++;
                }
                j++;
            }
        }

        while(st.size()>0){
            char str=st.top();
            st.pop();
            ans[j]=str;
            j++;
        }
        
        s=ans;
    }
};