class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        int n=nums.size();
        for(int i=0;i<n;i++) pq.push(nums[i]);
        
        int sum=0;
        for(int i=0;i<n;i++) sum+=nums[i];
        while(k>0){
            int ele=pq.top();
            if(ele==0) break;
            pq.pop();
            sum-=ele;
            pq.push(-1*ele);
            sum+=(-ele);
            k--;
        }
        return sum;
    }
};