class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        int indx=0;
        vector<int> groups(n);
        groups[0]=1;
        for(int i=1; i<n; i++){
            if(s[i]==s[i-1]){
                groups[indx]++;
            }
            else{
                indx++;
                groups[indx]++;
            }
        }
        int ans=0;
        for(int i=1; i<n; i++){
            ans = ans+ min(groups[i-1], groups[i]);
        }
        return ans;
    }
};