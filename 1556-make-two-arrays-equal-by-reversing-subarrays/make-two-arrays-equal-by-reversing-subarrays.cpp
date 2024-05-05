class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        if(target.size()!=arr.size()) return false;
        unordered_map<int,int> m;
        for(auto ele : arr){
            m[ele]++;
        }
        for(auto ele : target){
            if(m.find(ele)!=m.end()){
                m[ele]--;
                if(m[ele]==0){
                    m.erase(ele);
                }
            }else {
                return false;
            }
        }

        return true;
    }
};