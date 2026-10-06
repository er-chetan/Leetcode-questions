class Solution {
public:
    string reverseVowels(string s) {
        int i=0,j=s.size()-1;
        int prev,next;

        bool find1=false;
        bool find2=false;

        while(i<=j){
            if(s[i]=='a' || s[i]=='i' || s[i]=='e' || s[i]=='o' ||  s[i]=='u' || s[i]=='A' || s[i]=='I' || s[i]=='E' || s[i]=='O' || s[i]=='U'){
                prev=i;
                find1=true;
            }


            if(s[j]=='a' || s[j]=='i' || s[j]=='e' || s[j]=='o' ||  s[j]=='u' || s[j]=='A' || s[j]=='I' || s[j]=='E' || s[j]=='O' || s[j]=='U'){
                next=j;
                find2=true;
            }

            if(find1==true && find2==true){
                char c=s[next];
                s[next]=s[prev];
                s[prev]=c;
                find1=find2=false;
            }

            if(find1==false) i++;
            if(find2==false) j--;
           
        }

        return s;
    }
};