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
                // cout<<str<<" ";
                if(str[0]=='0') return false;
                int num = atoi(str.c_str());
                cout<<num<<" ";
                i=i+num;
                if(i>word.size()) return false;
                str="";
                find=false;
            }

            if(word[i]!=abbr[j]){
                cout<<"y";
                return false;
            }else{
                i++;
            }
            j++;
            
        }
        if(find==true && i<word.size()){
            if(str[0]=='0') return false;
            i=i+atoi(str.c_str());
        }
        if(j!=abbr.size() || i!=word.size()){
            cout<<"y";
            return false;
        }
        

        return true;
    }
};