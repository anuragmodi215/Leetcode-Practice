class Solution {
public:
    string reverseWords(string s) {
        int i=0, j=i;
        
        while(i<s.length()){
            while(j<s.length() and s[j] !=' ')j++;
            
            reverse(s.begin()+i, s.begin()+j);
            
            i=j+1;
            j=i;
        }
        return s;
    }
};