class Solution {
public:
    int canBeTypedWords(string text, string broken) {
        unordered_map<int,int> m;
        for(int i=0;i<broken.size();i++){
            m[broken[i]]++;
        }
        int count=0;
        if(text.size()==0){
            return count;
        }
        // count=1;
        bool find=false;
        for(int i=0;i<text.size();i++){
            if(text[i]==' '){
                if(find==false) count++;
                find=false;
            }

            if(m.find(text[i])!=m.end()){
                find=true;
            }
             
        }

        if(find==false) count++;

        return count;
    }
};