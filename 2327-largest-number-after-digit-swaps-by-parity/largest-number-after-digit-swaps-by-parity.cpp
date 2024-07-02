class Solution {
public:
    int largestInteger(int num) {
        priority_queue<int> p,q;
        string str=to_string(num);
        if(str.size()==1){
            return num;
        }
        // int i=0;
        for(char s : str){
            if((s-'0')%2==0) p.push(s-'0');
            else q.push(s-'0');
            // i++;
        }
        // cout<<p.top()<<" "<<q.top();
        for(char& s : str){
            if((s-'0')%2==0){
                s=p.top()+'0';
                p.pop();
            }else{
                s=q.top()+'0';
                q.pop();
            }
        }

        return stoi(str);
    }
};