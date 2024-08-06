class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string,int> m1,m2;
        for(int i=0;i<words1.size();i++){
            m1[words1[i]]++;
        }
        for(int i=0;i<words2.size();i++){
            m2[words2[i]]++;
        }

        int count=0;
        for(auto ele : m1){
            if(m2.find(ele.first)!=m2.end() && ele.second==1){
                if(m2[ele.first]==1){
                    count++;
                }
            }
        }


        return count;
    }
};