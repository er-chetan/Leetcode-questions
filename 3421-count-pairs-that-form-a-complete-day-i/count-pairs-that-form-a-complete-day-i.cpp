class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        int n=hours.size();
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            m[hours[i]]++;
        }
        int count=0;
        for(int i=0;i<n;i++){
            int num=hours[i];
            m[num]--;
            if(m[num]==0){
                m.erase(num);
            }
            for(auto ele : m){
                if((ele.first+num)%24==0) count=count+ele.second;
            }
        }

        return count;
    }
};