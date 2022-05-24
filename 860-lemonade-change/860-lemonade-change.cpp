class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int cntFive=0,cntTen=0,cntTwenty=0;
        int n = bills.size();
        for(int i=0; i<n; i++){
            if(bills[i]==5){
                cntFive++;
            } 
            else if(bills[i]==10){
                if(cntFive==0){
                    return false;
                }
                cntFive--;
                cntTen++;
            }
            else {
                if(cntTen>0 and cntFive>0){
                    cntTen--;
                    cntFive--;
                }
                else if(cntFive>=3){
                    cntFive = cntFive-3;
                }
                else return false;
            }
        }
        return true;
    }
};