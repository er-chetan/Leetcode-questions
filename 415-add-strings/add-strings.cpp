class Solution {
public:
    string addStrings(string num1, string num2) {
        int n=num1.size();
        int m=num2.size();
        string str="";
        int carry=0;
        int i=n-1,j=m-1;
        while(i>=0 && j>=0){
            int num=num1[i]-'0'+num2[j]-'0';
            if(carry>0){
                num=num+carry;
                carry=0;
            }
            cout<<num<<" ";
            if(num<10){
                str=str+to_string(num);
            }else{
                int n1=num%10+carry;
                str=str+to_string(n1);
                carry=num/10;
            }
            i--;
            j--;
        }
        if(i>=0){
            while(i>=0){
                int num=num1[i]-'0';
                if(carry>0){
                    num=num+carry;
                    carry=0;
                }
                if(num<10){
                    str=str+to_string(num);
                }else{
                    int n1=num%10+carry;
                    str=str+to_string(n1);
                    carry=num/10;
                }
                i--;
            }
        }
    
        if(j>=0){
            while(j>=0){
                int num=num2[j]-'0';
                cout<<num<<" j ="<<j;
                if(carry>0){
                    num=num+carry;
                    carry=0;
                }
                if(num<10){
                    str=str+to_string(num);
                }else{
                    int n1=num%10+carry;
                    str=str+to_string(n1);
                    carry=num/10;
                }
                j--;
            }
        }
        if(carry>0){
            str+=to_string(carry);
        }

        reverse(str.begin(),str.end());
        return str;
    }
};