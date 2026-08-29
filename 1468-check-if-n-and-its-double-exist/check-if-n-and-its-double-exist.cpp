class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int,int> m;

        for(int i=0;i<arr.size();i++){
            m[arr[i]]++;
        }

        for(int i=0;i<arr.size();i++){
            // if(arr[0]%2!=0) continue;
            m[arr[i]]--;
            if(m[arr[i]]==0){
                m.erase(arr[i]);
            }

            if(m.find(arr[i]*2)!=m.end() || (arr[i]%2==0 && m.find(arr[i]/2)!=m.end())){
                cout<<arr[i];
                return true;
            }
        }


        return false;


    }
};