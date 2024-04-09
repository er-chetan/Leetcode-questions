class Solution {
public:
     
    string shortestCompletingWord(string s, vector<string>& words) {
        // sort(words.begin(),words.end());
        int mini=INT_MAX;
        string ans="";
        unordered_map<char,int> m;
        for(int i=0;i<s.size();i++){
            if(isalpha(tolower(s[i]))) m[tolower(s[i])]++;
        }

        for(auto word : words){
            unordered_map<char,int> g;
            for(int i=0;i<word.size();i++){
                g[word[i]]++;
            }
            bool find=false;
            int count=0;
            for(auto ele : m){
                if(g.find(ele.first)!=g.end()){
                    if(ele.second>g[ele.first]){
                        count--;
                    }
                    count++;
                }
            }

            if(count==m.size() && mini>word.size()){
                ans= word;
                cout<<"ans->"<<ans<<endl;
                mini=word.size();
            }
        }
        
        return  ans;

    }
};