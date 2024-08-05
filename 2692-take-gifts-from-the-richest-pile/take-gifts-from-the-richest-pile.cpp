class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        for(int i=0;i<gifts.size();i++){
            pq.push(gifts[i]);
        }
        int i=1;
        while(i<=k){
            int num=pq.top();
            pq.pop();
            pq.push(sqrt(num));
            i++;
        }
        long long int sum=0;
        while(!pq.empty()){
            long long num=int(pq.top());
            sum+=num;
            cout<<sum<<" ";
            pq.pop();
        }

        return sum;
    }
};