class Solution {
public:
    int rem=0;
    bool isPowerOfThree(int n) {
        if(rem==1 || rem==2 || n<1){
            return false;
        }
        if(n==1 && rem==0){
            return true;
        }
        rem=n%3;
        n=n/3;
        
        return isPowerOfThree(n);
    }
};