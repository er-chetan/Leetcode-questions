class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        int w1=-1,w2=-1,n=wordsDict.size();
        int i=0,j=0;
        int mini=INT_MAX;
        while(i<n){
            if(wordsDict[i]==word1){
                w1=i;
            }
            if(wordsDict[j]==word2){
                w2=j;
            }

            if((w1!=-1 && w2!=-1) && abs(w2-w1)<mini){
                mini=abs(w2-w1);
                cout<<"yes :"<<mini<<endl;
            }

            i++;
            j++;
        }

        cout<<"w ="<<w1<<" "<<w2<<endl;
        cout<<mini;

        return mini;
    }
};