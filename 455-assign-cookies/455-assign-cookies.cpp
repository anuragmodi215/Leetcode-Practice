class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int cookieSize=s.size();
        if(cookieSize==0) return cookieSize;
        int cnt=0;
        int n=g.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int j=0;
        for(int i=0; i<cookieSize and j<n; i++){
            if(g[j]<=s[i]){
                j++;
                cnt++;
            }
        }
        
        return cnt;
    }
};