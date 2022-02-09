class Solution {
public:
    string helper(string s, string str, int n, int m){
        vector<vector<int>>dp(n+1,vector<int>(m+1));
        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                if(s[i-1]==str[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        int i=n,j=m;
        string seq="";
        while(i>0 and j>0){
            if(s[i-1]==str[j-1]){
                seq.push_back(s[i]);
                i--; j--;
            }
            else{
                if(dp[i-1][j]>dp[i][j-1]) i--;
                else j--;
            }
        }
        //reverse(seq.begin(),seq.end());
        return seq;
    }
    int longestPalindromeSubseq(string s) {
        string str=s;
        reverse(s.begin(),s.end());
        cout<<s<<" "<<str<<endl;
        int n=s.size();
        int m=str.size();
        string seq=helper(s,str,n,m);
        cout<<seq<<endl;
        return seq.size();
    }
};