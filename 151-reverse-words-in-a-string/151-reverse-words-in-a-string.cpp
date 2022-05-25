class Solution {
public:
    string getWord(int i, int n, string &s){
        int j = i;
        while(j<n and s[j]!=' '){
            j++;
        }
        return s.substr(i,j-i);
    }
    string reverseWords(string s) {
        string ans = "";
        int n = s.size();
        for(int i=0; i<n; i++){
            if(s[i]==' ') continue;
            string word = getWord(i,n,s);
            if(ans.size()==0){
                ans = word+ans;
            }
            else{
                ans = word+" "+ans;
            }
            i = i+word.size();
        }
        return ans;
    }
};