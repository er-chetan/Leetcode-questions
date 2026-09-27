class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int sum=0;
        int n=code.size();
        vector<int> ans(n);
        
        if(k==0){
            for(int i=0;i<n;i++){
                code[i]=0;
            }
        }else if(k>0){
            for(int i=0;i<k;i++){
                sum+=code[i];
            }
        
            int j=0;
            int i=k;
            while(j<n){
                sum=sum-code[j]+code[i];
                // cout<<sum<<" "<<code[j]<<" "<<code[i]<<endl;
                ans[j]=sum;
                j++;
                i++;
                if(i==n){
                    // cout<<"y";
                    i=0;
                }
            }
        }else{
            for(int i=n-1;i>=(n+k);i--){
                sum+=code[i];
            }
            ans[0]=sum;
            int j=1;
            int i=n+k;
            while(j<n){
                // cout<<sum<<" "<<code[i]<<" "<<code[j]<<endl;
                sum=sum-code[i]+code[j-1];
                
                ans[j]=sum;
                j++;
                i++;
                if(i==n) i=0;

            }
        }

        return ans;
    }
};