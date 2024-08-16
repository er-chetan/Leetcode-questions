class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n=arr.size();
        vector<int> prefix(n,0);
        prefix[0]=arr[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+arr[i];
        }
        // for(auto ele : prefix) cout<<ele<<" ";
        int totalsum=0;
        for(int len=1;len<=n;len+=2){
            for(int start=0;start+len<=n;start++){
                int end=start+len-1;
                if(start>0){
                    totalsum+=(prefix[end]-prefix[start-1]);
                }else{
                    totalsum+=prefix[end];
                }
            }
        }

        cout<<totalsum;

        return totalsum;
    }
};