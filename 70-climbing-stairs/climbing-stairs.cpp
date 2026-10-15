class Solution {
public:
    int climbStairs(int n) {
        // vector<int> dp(n+1); 

        // if(n==1) return 1;
        // if(n==2) return 2;

        // dp[0]=0;
        // dp[1]=1;
        // dp[2]=2;

        // for(int i=3;i<=n;i++){
        //     dp[i]=dp[i-1]+dp[i-2];
        // }


        // return dp[n];



        ////// space complexity improve

        if(n==1) return 1;
        if(n==2) return 2;

        vector<int> dp(4);

        dp[0]=0;
        dp[1]=1;
        dp[2]=2;

        for(int i=3;i<=n;i++){
            dp[3]=dp[1]+dp[2];
            cout<<dp[3]<<" ";
            dp[1]=dp[2];
            dp[2]=dp[3];
        }


        return dp[3];


        


    }
};