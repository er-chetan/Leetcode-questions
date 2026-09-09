class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> s;

        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        bool find=false;
        int i=1;
        int num,result;
        while(find==false){
            num=k*i;

            if(s.find(num)==s.end()){
                result=num;
                find=true;
            }
            i++;
        }


        return result;
    }
};