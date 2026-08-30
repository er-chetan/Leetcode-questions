class Solution {
public:
    int count=0;
    void bits(int n){
        if(n<=1){
            count++;
            return;
        }

        if(n%2==0){
            return bits(n/2);
        }else{
            count++;
            cout<<count<<" ";
            return bits(n/2);
        }
        
    }
    int hammingWeight(int n) {
        bits(n);
        return count;
    }
};