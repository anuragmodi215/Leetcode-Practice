class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>mp;
        int n = s.size();
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;
        int sum=0;
        for(int i=n-1; i>=0; i--){
            int temp1=mp[s[i]];
            if(i-1>-1){
                int temp2=mp[s[i-1]];
                //cout<<temp2;
                if(temp2<temp1){
                    temp1-=temp2;
                    i--;
                }
                // cout<<temp1<<endl;
            }
            cout<<temp1<<endl;
            sum=sum+temp1;
        }
        return sum;
    }
};