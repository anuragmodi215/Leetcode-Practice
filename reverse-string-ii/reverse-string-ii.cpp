class Solution {
public:
    string reverseStr(string s, int k) {
        int n=s.size();
        bool ok=1;
        for(int i=0; i<n; i=i+k){
            if(ok){
                if(i+k-1>=n) reverse(s.begin()+i,s.end());
                else
                reverse(s.begin()+i,s.begin()+i+k);
                ok=0;
            }
            else
            ok=1;
        }
        return s;
    }
};