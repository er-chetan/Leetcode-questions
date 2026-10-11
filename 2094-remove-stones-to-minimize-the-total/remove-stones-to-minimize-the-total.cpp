class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        // sort(piles.begin(),piles.end());
        priority_queue<int> pq;
        int n=piles.size();
        for(int i=0;i<n;i++){
            pq.push(piles[i]);
        }

        while(k>0){
            int num=pq.top();
            if(num%2==0){
                num=floor(num)/2;
            }else {
                num=(floor(num)/2)+1;
            }
            // cout<<num<<" ";
            pq.pop();
            pq.push(num);
            k--;
        }
        
        int sum=0;
        while(pq.size()>0){
            sum+=pq.top();
            pq.pop();
        }
        cout<<sum;
        return sum;
    }
};