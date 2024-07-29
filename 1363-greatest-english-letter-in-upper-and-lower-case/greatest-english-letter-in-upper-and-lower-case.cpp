class Solution {
public:
    string greatestLetter(string s) {
        unordered_set<char> st;
        char ch='<';
        for(int i=0;i<s.size();i++){
            st.insert(s[i]);
        }

        for(auto ele : st){
            if(islower(ele)){
                char temp=toupper(ele);
                if(temp>ch && st.find(temp)!=st.end()){
                    ch=temp;
                    cout<<ch<<" ";
                }
            }
        }

        if(ch=='<'){
            return "";
        }
        string str="";
        str+=ch;
        return str;

    }
};