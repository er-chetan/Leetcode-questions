class Solution {
public:
    bool isSDN(int number){
        int num=number;
        while(num>0){
            int deno=num%10;
            num/=10;
            if(deno==0 || number%deno!=0){
                return false;
            }
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int n=left;n<=right;n++){
            if(isSDN(n)){
                ans.push_back(n);
            }
        }


        for(auto ele : ans){
            cout<<ele<<" ";
        }

        return ans;
    }
};