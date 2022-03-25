class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n=s.size();
        vector<int>ans;
        int lo=0, hi=n;
        for(int i=0; i<n; i++){
            if(s[i]=='I') ans.push_back(lo++);
            else ans.push_back(hi--);
        }
        ans.push_back(hi);
        return ans;
    }
};