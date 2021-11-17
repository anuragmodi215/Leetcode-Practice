class Solution {
public:
    bool isSubsequence(string s, string t) {
        int og = t.size();
        int seq = s.size();
        int i=0,j=0;
        int cnt=0;
        while(i<seq and j<og){
            if(s[i]==t[j]) i++;
            j++;
        }
        if(i==seq) return true;
        else return false;
    }
};