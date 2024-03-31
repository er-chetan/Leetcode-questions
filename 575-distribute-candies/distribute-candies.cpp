class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n=candyType.size();
        unordered_set<int> s;
        for(auto ele : candyType) s.insert(ele);
        if(s.size()<=n/2) return s.size();

        return n/2;


    }
};