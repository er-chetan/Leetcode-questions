class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<int,int> m;
        for(auto ele : stones) m[ele]++;
        int count=0;
        for(int i=0;i<jewels.size();i++){
            if(m.find(jewels[i])!=m.end()) count+=m[jewels[i]];
        }
        return count;
    }
};