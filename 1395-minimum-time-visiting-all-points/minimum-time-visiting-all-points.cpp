class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n=points.size();
        int res=0;
        for(int i=1;i<n;i++){
            cout<<"yes"<<" ";
            int x_diff=abs(points[i][0]-points[i-1][0]);
            int y_diff=abs(points[i][1]-points[i-1][1]);

            res+=max(x_diff,y_diff);

        }

        cout<<res;
        return res;
    }
};