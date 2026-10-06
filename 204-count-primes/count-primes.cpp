class Solution {
public:
    int countPrimes(int n) {
        vector<int> v(n+1,1);
        // if(n==0 || n==2 || n==1) return 0;
        
        for(long long i=2 ;i<=sqrt(n);i++){
            if(v[i]){
                for(long long j=i*i;j<n;j=j+i){
                    v[j]=0;
                }
            }
        }
        long long count=0;
        for(int i=2;i<n;i++){
            if(v[i]) count++;
        }
        
        return count;
    }
};

