class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        double sum=0;
        for(int i=0;i<k;i++){
            sum+=arr[i];
        }
        int count=0;
        double avrg=sum/k;
        if(avrg>=threshold){
            count++;
        }
        int j=0;
        for(int i=k;i<arr.size();i++,j++){
            sum=sum-arr[j]+arr[i];
            avrg=sum/k;
            if(avrg>=threshold){
                count++;
            }
        }

        return count;

    }
};