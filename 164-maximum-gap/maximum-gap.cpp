class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n=nums.size();
        priority_queue<int> pq;

        if(n<2) return 0;
        if(n==2) return max((nums[0]-nums[1]),(nums[1]-nums[0]));

        for(int i=0;i<n;i++) pq.push(nums[i]);
    
        int maxi1=INT_MIN,maxi2=INT_MIN;
        int result=INT_MIN;
        while(pq.size()>2){
            int num3=pq.top();
            pq.pop();
            int num2=0,num1=0;

            if(pq.size()>0){
                num2=pq.top();
                pq.pop();
            }

            if(pq.size()>0){
                num1=pq.top();
                pq.pop();
            }

            if(num2!=0) pq.push(num2);
            if(num1!=0) pq.push(num1);
            
            maxi1=num3-num2;
            maxi2=num2-num1;

            if(result<max(maxi1,maxi2)){
                result=max(maxi1,maxi2);
            }
        }

        return result;
    }
};