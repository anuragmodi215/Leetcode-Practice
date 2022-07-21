class Solution {
public:
    int left=0;
    int right = 0;
    int ans = 0;
    void helper(int i, int j, string&s){
        int n = s.size();
        while(i>=0 and j<n){
            if(s[i]==s[j]){
                //cout<<s[i];
                if(ans<j-i+1){
                    ans = j-i+1;
                    left = i;
                    right = j;
                }
                i--;j++;
            }
            else break;
        }
        //return ans;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        int ans = INT_MIN;
        for(int i=0; i<n-1; i++){
            helper(i,i,s);
            helper(i,i+1,s);
        }
       
        // cout<<left<<endl;
        // cout<<right<<endl;
        return s.substr(left,right-left+1);
    }
};