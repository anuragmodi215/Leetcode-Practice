class Solution {
public:
    bool isVowel(char x){
        if(x=='a' or x=='e' or x=='i' or x=='o' or x=='u' or x=='A' or x=='E' or x=='I' or x=='O' or x=='U') return true;
        return false;
    }
    string reverseVowels(string s) {
        int n = s.size();
        int i=0, j=n-1;
        
        while(i<j){
            char x,y;
            if(isVowel(s[i]) and isVowel(s[j])){
                swap(s[i],s[j]);
                i++;j--;
            }
            else{
            if(!isVowel(s[i])) i++;
            if(!isVowel(s[j])) j--;
            }
        }
        return s;
    }
};