class Solution {
public:
    string getWord(string &s, int i){
        int j=i;
        int n = s.size();
        while(j<n and s[j] != ' '){
            j++;
        }
        string temp = s.substr(i,j-i);
        return temp;
    }
    string reverseWords(string s) {
        string ans = "";
        int n = s.size();
        for(int i=0; i<n; i++){
            if(s[i]==' ')continue;
            string word = getWord(s,i);
            cout<<word<<endl;
            if(ans==""){
                ans = word;
            }
            else{
                ans = word+" "+ans;
            }
            
            i = i+word.size();
        }
        return ans;
    }
};