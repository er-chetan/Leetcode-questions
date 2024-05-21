    bool cmp(pair<int,int>& p,pair<int,int>& q){
        
        return p.first>q.first;
    }

class Solution {
public:
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        vector<pair<int,int>> v;
        int result=0;
        for(auto ele : boxTypes){
            pair<int,int> p;
            p.first=ele[1];
            p.second=ele[0];
            v.push_back(p);
        }
        sort(v.begin(),v.end(),cmp);
        for(int i=0;i<v.size();i++){
            pair<int,int> temp=v[i];
            if(temp.second<truckSize){
                result+=(temp.second*temp.first);
                truckSize-=temp.second;
            }else{
                result+=(truckSize*temp.first);
                break;
            }
        }
        return result;
    }
};