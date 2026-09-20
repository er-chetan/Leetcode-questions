class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        // s.push(s[0]);
        string ans="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='A' || s[i]=='C'){
                st.push(s[i]);
            }else if(st.size()>0 && (st.top()=='A' && s[i]=='B')){
                // cout<<"AB"<<endl;
                st.pop();
            }else if(st.size()>0 && (st.top()=='C' && s[i]=='D')){
                // cout<<"CD"<<endl;
                st.pop();
            }else{
                while(st.size()>0){
                    // cout<<st.top()<<"top"<<endl;
                    ans.push_back(st.top());
                    st.pop();
                }
                ans+=s[i];
            }
        }
        while(st.size()>0){
            // cout<<st.top()<<"top"<<endl;
            ans.push_back(st.top());
            st.pop();
        }
        // for(auto ele :ans){
        //     cout<<ele<<" ";
        // }

        return ans.size();
    }
};