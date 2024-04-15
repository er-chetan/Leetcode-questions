class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<int> v((m+n),0);
        int i=0,j=0,k=0;
        if(n==0){
            while(j<m){
                v[k]=nums2[j];
                k++;
                j++;
            }
        }else if(m==0){
            while(i<n){
                v[k]=nums1[i];
                k++;
                i++;
            }
        }else{
                while(i<n && j<m){
                if(nums1[i]<=nums2[j]){
                    v[k]=nums1[i];
                    k++;
                    i++;
                }else{
                    v[k]=nums2[j];
                    k++;
                    j++;
                }

                if(i==n){
                    while(j<m){
                        v[k]=nums2[j];
                        k++;
                        j++;
                    }
                }
                if(j==m){
                    while(i<n){
                        v[k]=nums1[i];
                        k++;
                        i++;
                    }
                } 
            }
        }
        

         
        int t=v.size()/2;
        if(v.size()%2!=0 || t==0){
            return v[t];
        }
         
        return float(v[t-1]+v[t])/2;

    }
};