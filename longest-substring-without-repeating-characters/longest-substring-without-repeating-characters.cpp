class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> st;
        int l=0, r=0;
        int n=s.size();
        int ml = 0;
        while(l<n and r<n){
            if(st.find(s[r]) == st.end()){
                st.insert(s[r]);
                ml = max(ml, r-l+1);
                r++;
            }
            else {
                st.erase(s[l]);
                l++;
            }
        }
        return ml;
    }
};