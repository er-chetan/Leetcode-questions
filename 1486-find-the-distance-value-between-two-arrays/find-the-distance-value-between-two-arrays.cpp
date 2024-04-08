class Solution {
public:

    bool find(vector<int>& arr2, int d,int num){

        int lo=0;
        int hi=arr2.size()-1;

        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(abs(num-arr2[mid])<=d){
                return false;
            }else if(arr2[mid]<num){
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }

        return true;
    }
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(),arr2.end());
        int count=0;
        for(int i=0;i<arr1.size();i++){
            if(find(arr2,d,arr1[i])==true) count++;
        }

        return count;
    }
};