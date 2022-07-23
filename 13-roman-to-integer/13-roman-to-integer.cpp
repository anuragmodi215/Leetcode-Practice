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
    
        int sum = 0;
        int n = s.size();
       for(int i=0; i<n; i++){
           int newNumber = mp[s[i]];
           int j=i-1;
           int toRemove=0;
           while(j>=0 and mp[s[j]]<newNumber){
               toRemove+=mp[s[j]];
               sum-=mp[s[j]];
               j--;
           }
           newNumber-=toRemove;
           sum+=newNumber;
       }
        return sum;
    }
};