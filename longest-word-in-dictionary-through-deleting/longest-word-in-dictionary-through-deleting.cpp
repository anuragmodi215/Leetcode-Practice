class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string ans;
        for( string word:dictionary){
            int i=0,j=0;
            int wrdSize=word.size();
            int sSize=s.size();
            while(i<wrdSize and j<sSize){
                if(word[i]==s[j]) i++;
                j++;
            }
            int n = word.size();
            if(i==n and ((ans.size()==n and ans>word) or ans.size()<n)) 
                ans = word;
        }
        return ans;
    }
};