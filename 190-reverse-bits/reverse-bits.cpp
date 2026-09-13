class Solution {
public:
    string ans;
    int helper(int n){
        if(n==0){
            return 0;
        }
        if(n==1){
            ans+="1";
            return 1;
        }else if (n%2==0){
            ans+="0";
            return helper(n/2);
        }else{
            ans+="1";
            return helper(n/2);
        }
    }
    int reverseBits(int n) {
        int a=helper(n);
        // cout<<ans.size()<<" ";
        int size=32-ans.size();

        for(int i=1;i<=size;i++){
            ans+="0";
        }
        // cout<<ans<<endl;
        int num=0;
        int bit=31;
        for(int i=0;i<ans.size();i++){
            int n1=(ans[i]-'0')*pow(2,bit);
            bit--;
            // cout<<n1<<" ";
            num=num+n1;
        }
        return num;
    }
};