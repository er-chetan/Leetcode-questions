class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string,int> m1,m2;

        for(int i=0;i<list1.size();i++){
            m1[list1[i]]=i;
        }

        for(int i=0;i<list2.size();i++){
            m2[list2[i]]=i;
        }
        int min=INT_MAX;
        for(auto ele : m1){
            // cout<<ele.second<<" ";
            if(m2.find(ele.first)!=m2.end()){
                // cout<<"yes";
                int sum=m1[ele.first]+m2[ele.first];
                if(min>sum){
                    min=sum;
                }
            }
        }
        vector<string> v;
        cout<<"minimum"<<min;

        for(auto ele : m1){
            if(m2.find(ele.first)!=m2.end()){
                int sum=m1[ele.first]+m2[ele.first];
                if(sum==min){
                    v.push_back(ele.first);
                }
            }
        }

        

        return v;

    }
};