class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        set<int> st;
        int sum=0;
        for(auto ele : nums) {
            if(ele>0 && st.find(ele)==st.end()){
                sum+=ele;
                st.insert(ele);
            }
        }

        return st.size();

        


    }
};