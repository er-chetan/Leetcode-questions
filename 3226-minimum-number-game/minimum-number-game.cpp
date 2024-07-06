class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        int i=0;
        while(pq.size()>0){
            int alice=pq.top();
            pq.pop();
            int bob=pq.top();
            pq.pop();
            nums[i]=bob;
            i++;
            nums[i]=alice;
            i++;
        }

        return nums;
    }
};