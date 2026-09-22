class Solution {
public:
    int calculateTime(string keyboard, string word) {
        unordered_map<char,int> m;

        for(int i=0;i<keyboard.size();i++){
            m[keyboard[i]]=i;
        }

        int prev=-1;
        int sum=0;
        for(int i=0;i<word.size();i++){

            if(m.find(word[i])!=m.end()){
                
                if(prev==-1){
                    
                    prev=m[word[i]];
                    sum=prev;
                    // cout<<sum<<" "<<prev<<endl;
                }else{
                    sum=sum+abs(prev-m[word[i]]);
                    prev=m[word[i]];
                    // cout<<sum<<" "<<m[word[i]]<<endl;
                }
            }

            
        }
        // cout<<"sum"<<sum;
        return sum;
    }
};