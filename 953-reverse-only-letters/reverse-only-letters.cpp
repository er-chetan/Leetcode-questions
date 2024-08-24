class Solution {
public:
    string reverseOnlyLetters(string s) {
        int i=0,j=s.size()-1;
        while(i<j){
            if(isalpha(s[i]) && isalpha(s[j])){
                char ch=s[j];
                s[j]=s[i];
                s[i]=ch;
                i++;
                j--;
            }else if(!isalpha(s[i]) && isalpha(s[j])){
                i++;
            }else if(isalpha(s[i]) && !isalpha(s[j])){
                j--;
            }else{
                i++;
                j--;
            }
        }

        return s;
    }
};