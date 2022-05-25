class Solution {
public:
    int romanToInt(string s) {
        int nums=0;
        unordered_map<char,int>mp;
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;
        
        int n=s.size();
        for(int i=0; i<n; i++){
            int currNums = mp[s[i]];
            int j=i-1;
            while(j>=0 and mp[s[j]]<currNums){
                currNums-=mp[s[j]];
                nums-=mp[s[j]];
                j--;
            }
            nums+=currNums;
        }
        return nums;
    }
};