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
        for(int i=0;i<s.size();i++){
            sum+=v[i];
            k=i;
            if(sum<=maxCost){
                count++;
            }else{
                cout<<sum<<endl;
                sum=sum-v[i];
                break;
            }
            
        }
        
        for(auto ele : v) cout<<ele<<" ";
        cout<<"\n"<<k<<endl;
        
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
                cout<<"sum "<<sum<<" "<<i<<" "<<j<<endl; 
                if(max_len<count) max_len=count;
            }
        }

        if(max_len<count) max_len=count;

        cout<<"max :"<<max_len;

        return max_len;
    }
};