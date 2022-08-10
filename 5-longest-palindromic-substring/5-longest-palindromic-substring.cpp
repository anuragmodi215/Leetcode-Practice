class Solution {
public:
    int start=0;
    int end=0;
    int len=0;
    void helper(string&s, int ind,int ind2){
        int i=ind,j=ind2;
        int n = s.size();
        while(i>=0 and j<n){
            if(s[i]==s[j]){
                if(j-i+1>len){
                    len=j-i+1;
                    start = i;
                    end=j;
                }
                i--;j++;
            }
            else break;
        }
       // cout<<start<<" "<<len<<endl;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        for(int i=0; i<n; i++){
            helper(s,i,i);
            helper(s,i,i+1);
        }
        //cout<<len;
        return s.substr(start,len);
    }
};