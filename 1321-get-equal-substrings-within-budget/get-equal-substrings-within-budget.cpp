class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        
        vector<int> v(s.size());

        for(int i=0;i<s.size();i++){
            v[i]=abs(s[i]-t[i]);
        }
        int count=0;
        int sum=0;
        int k=0;


        // this is first window i.e statisfy the condition
        for(int i=0;i<s.size();i++){
            sum+=v[i];
            k=i;
            if(sum<=maxCost){
                count++;
            }else{
                sum=sum-v[i];
                break;
            }
        }

        int j=0;
        int i;
        int max_len=INT_MIN;

        if(max_len<count) max_len=count;

        for(i=k;i<v.size();i++){
            sum=sum+v[i];
            if(sum>maxCost){
                sum=sum-v[j];
                j++;
            }else{
                count=i-j+1;
                if(max_len<count) max_len=count;
            }
        }

        // if(max_len<count) max_len=count;

        return max_len;
    }
};