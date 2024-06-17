class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<double,pair<int,int>>> pq;
        // vector<int> ans(2);
        int n=arr.size();
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                double val=(arr[i]*1.0)/(arr[j]*1.0);
                pq.push({val,{arr[i],arr[j]}});
                if(pq.size()>k){
                    pq.pop();
                } 
            }
        }
        // cout<<pq.top();
        return {pq.top().second.first,pq.top().second.second};
    }
};