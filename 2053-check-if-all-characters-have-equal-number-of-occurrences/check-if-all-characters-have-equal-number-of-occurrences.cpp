class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<int,int> m;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
        } 

        int num=m[s[0]];
        for(auto ele : m){
            if(ele.second!=num){
                return false;
            }
        }


        return true;
    }
};