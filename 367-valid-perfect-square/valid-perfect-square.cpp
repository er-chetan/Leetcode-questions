class Solution {
public:
    bool isPerfectSquare(int num) {
        long long target=num;

        long long lo=1,hi=num,mid;

        while(lo<=hi){
            mid=(lo+hi)/2;

            if(mid*mid==target){
                return true;
            }else if(mid*mid>target){
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }

        return false;
    }
};