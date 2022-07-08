class Solution {
public:
    bool checkPal(int i, int j, string&s){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i=0; int j = s.size()-1;
        while(i<j){
            if(s[i]==s[j]){
                //cout<<i<<" "<<j<<endl;
                i++;j--;
                if(i>=j) return true;
            }
            else{
                int front=i;
                int back=j;
                if(checkPal(front+1,back,s)) return true;
                if(checkPal(front,back-1,s)) return true;
                return false;
            }
        }
        //if(i>j) return true;
        return false;
    }
};