class Solution {
public:
    int helper(string s, int k){
        int n = s.size();
        if(n==0 or n<k) return 0;
        
        int freq[26]={0};
        for(int i=0; i<n; i++){
            freq[s[i]-'a']++;
        }
        int i=0;
        //this is the place where we are getting our ans i.e i==n
        while(i<n and freq[s[i]-'a']>=k){
            i++;
        }
        if(i==n) return i;
        
        int firstHalf = helper(s.substr(0,i),k);
        while(i<n and freq[s[i]-'a']<k)i++;
        int secondHalf = 0;
        if(i<n and n-i>=k){
            secondHalf = helper(s.substr(i),k);
        }
        return max(firstHalf,secondHalf);
    }
    int longestSubstring(string s, int k) {
        return helper(s,k);
    }
};