class Solution {
public:
    int reverseDegree(string s) {
        int sum=0;
        // cout<<'a'-0;
        for(int i=0;i<s.size();i++){
            // cout<<s[i]-0<<" ";
            int incr_alpha=(26-((s[i]-0)-97));
            cout<<incr_alpha<<" ";
            int index=i+1;
            sum=sum+incr_alpha*index;
        }

        cout<<sum;

        return sum;
    }
};