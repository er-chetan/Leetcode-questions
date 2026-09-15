class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> ans;
        int carry=0;
        for(int i=num.size()-1;i>=0;i--){
            // cout<<k<<" ";
            int n=k%10;
            // cout<<n<<" ";
            int add_num=num[i]+n;
            cout<<add_num<<" ";

            if(add_num<9){
                if(carry==1){
                    ans.push_back((add_num+carry));
                }else{
                    // cout<<add_num<<" ";
                    ans.push_back(add_num);
                }
                carry=0;
            }else if(add_num==9 && carry==1){
                ans.push_back(0);
                carry=1;
            }else if(add_num==9 && carry==0){
                ans.push_back(9);
                carry=0;
            }else{
                
                ans.push_back((add_num+carry)%10);
                carry=1;
            }
            k=k/10;
            
        }

        // for(auto ele : ans){
        //    cout<<ele<<" ";
        // }
        
        while(k>0){
            int n=k%10;
            if(n<9){
                if(carry==1){
                    ans.push_back((n+carry));
                }else{
                    // cout<<add_num<<" ";
                    ans.push_back(n);
                }
                carry=0;
            }else if(n==9 && carry==1){
                ans.push_back(0);
                carry=1;
            }else if(n==9 && carry==0){
                ans.push_back(9);
                carry=0;
            }else{
                
                ans.push_back((n+carry)%10);
                carry=1;
            }
            k=k/10;
        }
        if(carry==1) ans.push_back(1);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};