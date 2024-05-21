    bool cmp(vector<int> &a,vector<int>& b){
        return a[1]>b[1];
    }

class Solution {
public:
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int result=0;
        sort(boxTypes.begin(),boxTypes.end(),cmp);
        for(int i=0;i<boxTypes.size() && truckSize!=0 ;i++){
            if(boxTypes[i][0]<truckSize){
                result+=(boxTypes[i][1]*boxTypes[i][0]);
                truckSize-=boxTypes[i][0];
            }else{
                result+=(truckSize*boxTypes[i][1]);
                truckSize=0;
            }
        }
        return result;
    }
};