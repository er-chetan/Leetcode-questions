class Solution {
public:
    string convertToTitle(int n) {
        string str="";
        while(n>0){
            n--;
            int a=n%26;
            str=str+char(a+'A');
            n=n/26;
        }
        reverse(str.begin(),str.end());
        return str;
    }
};