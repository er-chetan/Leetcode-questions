class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_map<char,string> m;
        vector<string> v={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        for(int i=0;i<26;i++){
            m[char(97+i)]=v[i];
        }
        unordered_set<string> st;
        for(int i=0;i<words.size();i++){
            string str=words[i];
            string s="";
            for(int j=0;j<str.size();j++){
                s+=m[str[j]];
            }
            st.insert(s);
        }


        return st.size();
    }
};