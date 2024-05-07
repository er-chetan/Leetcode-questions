class Solution {
public:
    bool isOneBitCharacter(vector<int>& a) {
        int n=a.size();
        int i=0;
        int j=i+1;
        while(j<n+1){
            if(a[i]==0 && j==n) return true;
            else if(a[i]==0 && j==n) return false;
            else if((a[i]==0 && a[j]==1) || (a[i]==0 && a[j]==0)){
                i=i+1;
                j=i+1;
            }else{
                i=i+2;
                j=i+1;
            }
        }

        return false;
    }
};