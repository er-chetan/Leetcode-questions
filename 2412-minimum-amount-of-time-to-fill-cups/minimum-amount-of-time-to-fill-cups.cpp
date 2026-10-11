class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int> pq;
        int count=0;
        for(auto ele : amount){
            if(ele>0){
                pq.push(ele);
            }
        }
        while(pq.size()>0){
            int num1=pq.top();
            pq.pop();
            // cout<<num1<<" ";
            if(pq.size()>0){
                int num2=pq.top();
                // cout<<num2;
                pq.pop();
                num2--;
                if(num2>0) pq.push(num2);
            }
            num1--;
            count++;
            if(num1>0) pq.push(num1);
            // cout<<endl;
        }

        // cout<<count;

        return count;
    }
};