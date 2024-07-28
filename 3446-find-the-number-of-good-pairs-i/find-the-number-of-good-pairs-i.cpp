class Solution {
public:
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        unordered_map<int,int> Nm,Dmr;
        for(int i=0;i<nums1.size();i++) Nm[nums1[i]]++;
        for(int i=0;i<nums2.size();i++) Dmr[nums2[i]*k]++;
        int count=0;
        for(auto n :  Nm){
            int ele=n.first;
            int freq=n.second;
            for(auto d : Dmr){
                if(ele%d.first==0){
                    count+=(freq*d.second);
                }
            } 
        }


        return count;
    }   
};