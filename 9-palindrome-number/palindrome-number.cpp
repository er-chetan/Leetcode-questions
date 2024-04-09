class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        if(x==INT_MAX) return false;
        if(x==INT_MIN) return false;
        long long num=x;
        long b=0;
        while(num>0){
            b=b*10+num%10;
            num=num/10;
        }
        cout<<b;
        if(b!=x) return false;
        return true;
    }
};