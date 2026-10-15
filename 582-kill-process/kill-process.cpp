class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int,vector<int>> mp;
        vector<int> ans;
        ans.push_back(kill);
        int n=ppid.size();
        for(int i=0;i<n;i++){
            mp[ppid[i]].push_back(i);
        }
        int val=kill;
        int i=0;
        while(i<ans.size()){
            if(mp.find(ans[i])!=mp.end()){
                auto it=mp[ans[i]];
                for(auto ele : it){
                    ans.push_back(pid[ele]);
                }
            }
            mp.erase(ans[i]);
            i++;
        }


        return ans;

    }
};