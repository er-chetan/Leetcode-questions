class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string str=to_string(num);
        if(str.size()==1) return 1;
        string s="";
        
        int count=0;
        int n=0;
        for(int i=0;i<str.size();i++){
            s+=str.substr(i,k);
            n=stoll(s);
            cout<<n<<" ";
            int checklen=s.size();
            if((n!=0 && num%n==0) && checklen==k){
                count++;
                cout<<"yes"<<" ";
            }
            s="";
        }

        return count;
    }
};