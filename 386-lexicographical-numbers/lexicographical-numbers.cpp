class Solution {
public:
    vector<int> v;
    void func(int i,int n){
        if(i>n) return;
        if(i<=n && i!=0) v.push_back(i);
        if(i!=0){
            for(int j=0;j<=9;j++){
                func(10*i+j,n);
            }
        }else{
            for(int j=1;j<=9;j++){
                func(10*i+j,n);
            }
        }
    }
    vector<int> lexicalOrder(int n) {
        func(0,n);
        return v;
    }
};