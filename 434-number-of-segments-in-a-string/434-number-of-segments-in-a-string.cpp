class Solution {
public:
    int countSegments(string s) {
        int n=s.size();
        int cnt=0;
        for(int i=0; i<s.size(); i++){
            int j=i;
            if(j<n and s[j]!=' '){
                while(j<n and s[j]!=' ') j++;
                if(j!=i)cnt++;
            }
            while(j<n and s[j]==' ') j++;
            i=j-1;
        }
        return cnt;
    }
};