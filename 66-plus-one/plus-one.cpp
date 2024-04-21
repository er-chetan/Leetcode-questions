class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        int num=0;
        if(digits[n-1]+1<10){
            digits[n-1]=digits[n-1]+1;
            return digits;
        }else{
            int m=digits.size()-1;
            cout<<"m->"<<m<<endl;
            int idx;
            for(int i=m;i>=0;i--){
                if(digits[i]+1>=10){
                    num=digits[i]+1;
                    digits[i]=num%10;
                }else{
                    digits[i]=digits[i]+1;
                    break;
                }
            }
        }


        if(digits[0]==0){
            digits[0]=1;
            digits.push_back(0);
        } 

        return digits;
    }
};