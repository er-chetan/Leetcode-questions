class Solution {
public:
    int dayOfYear(string date) {
        int n=date.size();
        string month="";
        month+=date[5];
        month+=date[6];
        int mon=stoi(month);
        string d="";
        d+=date[n-2];
        d+=date[n-1];
        int dat=stoi(d);

        int n_of_dates=0;
        n_of_dates+=dat;

        if(mon==1){
            return n_of_dates;
        }else{
            for(int i=1;i<mon;i++){
                if(i==1 || i==3 || i==5 || i==7 || i==8 || i==10 || i==12){
                    n_of_dates+=31;
                }else if(i==4 || i==6 || i==9 || i==11){
                    n_of_dates+=30;
                }else{
                    n_of_dates+=28;
                }
            }
        }

        /// leap year check;
        string leapyear;
        for(int i=0;i<4;i++){
            leapyear+=date[i];
        }
        int lp=stoi(leapyear);

        int rem=lp%100;
        if(rem==0){
            lp=lp/100;
            rem=lp;
        }
    
        if(rem%4==0 && mon>2){
            n_of_dates+=1;
        }

        
        
        return n_of_dates;
    }
};