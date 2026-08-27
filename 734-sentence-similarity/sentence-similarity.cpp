class Solution {
public:
    bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
       set<pair<string,string>> s;
       if(sentence1.size()!=sentence2.size()){
        return false;
       }

       for(int i=0;i<similarPairs.size();i++){
        s.insert({similarPairs[i][0],similarPairs[i][1]});
       }
    //    for(int i=0;i<similarPairs.size();i++){
    //     s.insert({similarPairs[i][1],similarPairs[i][0]});
    //    }
    
        int count=0;
       for(int i=0;i<sentence1.size();i++){
            if(sentence1[i]==sentence2[i]){
                count++;
                continue;
            }else if(s.find({sentence1[i],sentence2[i]})!=s.end()){
                count++;
                continue;
            }
            else if(s.find({sentence2[i],sentence1[i]})!=s.end()){
                count++;
                continue;
            }
       }
        cout<<count<<" "<<sentence1.size();
        if(count==sentence1.size()) return true;
       

        return false;
    }
};