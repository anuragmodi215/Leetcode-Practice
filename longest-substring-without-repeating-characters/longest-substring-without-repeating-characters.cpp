class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int l=0, r=0;
        set<char> st;
        int maxl=0;
        while(l<s.length() and r<s.length()){
           if(st.find(s[r])==st.end()){
               st.insert(s[r]);
               maxl=max(maxl,r-l+1);
               r++;
           }
            else{
                st.erase(s[l]);
                l++;
            }
        }
        return maxl;
    }
};