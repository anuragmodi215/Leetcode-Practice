class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char>set;
        int i=0,j=0,ans=0;
        int n=s.size();
        while(j<n){
            if(set.find(s[j]) == set.end()){
                set.insert(s[j++]);
                int l=set.size();
                ans = max(ans,l);
            }
            else{
                set.erase(s[i++]);
            }
        }
        return ans;
    }
};