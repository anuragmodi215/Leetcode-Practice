class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        if(n==0) return 0;
        unordered_set<char>set;
        int i=0,ans=0;
        int j=0;
        while(j<n){
            if(set.find(s[j])!=set.end()){
                set.erase(s[i++]);
            }
            else{
                set.insert(s[j++]);
            }
            
            ans=max(ans,(int)(set.size()));
        }
        ans=max(ans,(int)(set.size()));
        return ans;
    }
};