
class Solution {
public:
    
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        unordered_map<string,int> m;
        for(auto ele : positive_feedback){
            m[ele]=3;
        }
        for(auto ele : negative_feedback){
            m[ele]=-1;
        }
        
        priority_queue<pair<int,int>> pq;

        for(int i=0;i<report.size();i++){
            string temp=report[i];
            string str="";
            int count=0;
            for(int j=0;j<temp.size();j++){
                if(temp[j]!=' '){
                    str+=temp[j];
                }
                if((temp[j]==' ' || j==temp.size()-1) ){
                    cout<<str<<" ";
                    if(m.find(str)!=m.end()){
                        count+=m[str];
                    }
                    str="";
                }
            }
            cout<<count<<" ";
            pq.push({count,-student_id[i]});
            count=0;
        }

        vector<int> v;
        cout<<"\nyes"<<endl;;
        while(k--){
            cout<<pq.top().first<<" "<<pq.top().second<<endl;;
            v.push_back(-pq.top().second);
            pq.pop();
        }
        
        

        return v;
    }
};