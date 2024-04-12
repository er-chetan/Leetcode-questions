class Solution {
public:
    void solve(string s,int i,int &count){
        int j = s.length()-1;
        while(j>=i){
            int start = i;
            int e = j;
            bool done = true;
            while(start<=e){
                if(s[start] != s[e]){
                    done = false;
                    break;
                }
                start++;
                e--;
            }
            if(done){
                count++;
            }
            j--;
        }

    }
    int countSubstrings(string s) {
        int count = 0;
        for(int i=0;i<s.length();i++){
            solve(s,i,count);
        }
        return count;
    }
};