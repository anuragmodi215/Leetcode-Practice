class Solution {
public:
    void expandFromCenter(int firstIndex, int secondIndex, string &s, int &start, int &length, int n){
        int currLen = 0;
        int i = firstIndex;
        int j = secondIndex;
        while(i>=0 and j<n and s[i]==s[j]){
            i--;
            j++;
        }
        i=i+1;
        j=j-1;
        if(length<j-i+1){
            start = i;
            length = j-i+1;
        }
    }
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0;
        int length = 0;
        for(int i=0; i<n; i++){
            expandFromCenter(i,i,s,start,length,n);
            expandFromCenter(i,i+1,s,start,length,n);
        }
        return s.substr(start,length);
    }
};