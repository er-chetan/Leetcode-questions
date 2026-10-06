class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0 || n==2 || n==3) return false;
        // if(n)
        bool find=true;

        while(find==true && n>=4){
            if(n%4!=0) find=false;
            cout<<n<<" ";
            n=n/4;
        }

        if(n<4 && n!=1) return false;

        return find;
    }
};