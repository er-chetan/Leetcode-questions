class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        
        int i=0,j=0;
        string str="";
        bool find=false;
        while(j<abbr.size()){
            if(!isalpha(word[i])) return false;
            
            if(isdigit(abbr[j])){
                str+=abbr[j];
                cout<<str<<" ";
                j++;
                find=true;
                continue;
            }else if(find==true){
                if(str[0]=='0') return false;
                int num = atoi(str.c_str());
                i=i+num;
                if(i>word.size()) return false;
                str="";
                find=false;
            }

            if(word[i]!=abbr[j]) return false;
            else i++;
            j++;
            
        }
        if(find==true && i<word.size()){
            if(str[0]=='0') return false;
            i=i+atoi(str.c_str());
        }
        if(j!=abbr.size() || i!=word.size()) return false;
        

        return true;
    }
};