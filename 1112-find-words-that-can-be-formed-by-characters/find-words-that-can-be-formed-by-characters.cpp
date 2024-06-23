class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char,int> m;
        for(int i=0;i<chars.size();i++){
            m[chars[i]]++;
        }
        int count=0;
        for(auto ele : words){
            unordered_map<char,int> s;
            bool find=true;
            for(int i=0;i<ele.size();i++){
                s[ele[i]]++;
                if(m.find(ele[i])==m.end() || m[ele[i]]<s[ele[i]]){
                    find=false;
                    break;
                }
            }
            if(find==true){
                count+=ele.size();
            }
        }
        return count;

    }
};