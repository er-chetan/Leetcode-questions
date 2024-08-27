class Solution {
public:
    string convertToBase7(int num) {
        if(num==0) return "0";
        string str="";
        bool find=false;
        if(num<0){
            num=-num;
            find=true;
        }
        while(num>0){
            int rem=num%7;
            cout<<rem<<" ";
            num/=7;
             
            str+=to_string(rem);
            cout<<str<<" ";
        }
        if(find==true){
            str.push_back('-');
        }
        reverse(str.begin(),str.end());
        return str;
    }
};