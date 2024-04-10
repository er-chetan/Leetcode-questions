class Solution {
public:
    bool find132pattern(vector<int>& a) {
     
        stack<int> st;
        int num = INT_MIN;
        int n  = a.size();
        for(int i=n-1;i>=0;i--)
        {
            if(num>a[i])
                return true;
            
            while(!st.empty() && st.top()<a[i])
            {
                num = st.top();
                st.pop();
            }
            
            st.push(a[i]);
        }
        
        return false;
        
    }
};