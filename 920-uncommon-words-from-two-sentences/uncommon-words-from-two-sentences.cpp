class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> m1,m2;
        string str="";
        int n=s1.size();
        int m=s2.size();
        for(int i=0;i<n;i++){
            if(isalpha(s1[i])){
                str+=s1[i];
            }
            if(!isalpha(s1[i]) || i==n-1){
                m1[str]++;
                str="";
            }   
        }

        for(int i=0;i<m;i++){
            if(isalpha(s2[i])){
                str+=s2[i];
            }
            if(!isalpha(s2[i]) || i==m-1){
                m2[str]++;
                str="";
            }   
        }
 

        vector<string> v;
        for(auto ele : m1){
            if(m2.find(ele.first)==m2.end()){
                if(ele.second==1){
                    v.push_back(ele.first);
                }
            }
        }

        for(auto ele : m2){
            if(m1.find(ele.first)==m1.end()){
                if(ele.second==1){
                    v.push_back(ele.first);
                }
            }
        }

        return v;
    }
};