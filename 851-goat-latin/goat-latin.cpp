class Solution {
public:
    string toGoatLatin(string S) {
        unordered_set<char> vowel({'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'});
        int n =S.size(),i=0;
        stringstream s(S);
        string temp,res;
        int count=0;
        while(s>> temp){
            count++;
            if(vowel.find(temp[0])!=vowel.end()){
                temp=temp+"ma";
            }else{
                char c=temp[0];
                temp=temp.substr(1);
                temp =temp+c+"ma";
            }

            for(int i=0;i<count;i++){
                temp.push_back('a');
            }
            res=res+temp;
            res=res+' ';

        }

        res.pop_back();
        return res;
    }
};