class Solution {
public:
    bool validPalindrome(string s) {
        int i=0,j=s.size()-1;
        int cnt1=0,cnt2=0;
        while(i<j){
            if(s[i]==s[j]){
                i++;j--;
            }
            else break;
        }
        int k=i,l=j;
        while(k<l){
            if(s[k]==s[l]){
                k++;l--;
            }
            else{
                k++; cnt1++;
            }
        }
        while(i<j){
            if(s[i]==s[j]){
                i++;j--;
            }
            else{
                j--; cnt2++;
            }
        }
        if(cnt1<=1 or cnt2<=1) return true;
        return false;
    }
};