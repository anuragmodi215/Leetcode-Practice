class Solution {
public:
    int strt=0; int length = 0;
    void expandFromCenter(int i, int j, string &s, int n){
        int tempLen=0;
        while(i>=0 and j<n){
            if(s[i]==s[j]){
                tempLen = j-i+1;
                i--;j++;
            }
            else break;
        }
         if(tempLen>length){
             strt=i+1;
             length = tempLen;
         }
    }
    string longestPalindrome(string s) {
        int n = s.size();
        strt=0;
        length = 0;
        for(int i=0; i<n; i++){
            expandFromCenter(i,i,s,n);
            expandFromCenter(i,i+1,s,n);
        }
        return s.substr(strt,length);
    }
};