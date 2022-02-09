class Solution {
public:
    string lcs(string s, string str, int n, int m){
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
        string sequence="";
        while(i>0 and j>0){
            if(s[i-1]==str[j-1]){
                sequence.push_back(s[i-1]);
                i--;j--;
            }
            else{
                if(dp[i-1][j]>dp[i][j-1]){
                    i--;
                }
                else{
                    j--;
                }
            }
        }
        
        reverse(sequence.begin(),sequence.end());
        cout<<sequence<<endl;
        return sequence;
        
    }
    string shortestCommonSupersequence(string s, string str) {
        int n=s.size();
        int m=str.size();
        string sequence=lcs(s,str,n,m);
        int o=sequence.size();
        int i=0,j=0,k=0;
        string ans="";
        while(i<n and j<m and k<o){
            if(s[i]==str[j] and s[i]==sequence[k]){
                ans.push_back(s[i]);
                i++;j++;k++;
            }
            else{
                if(s[i]==sequence[k]){
                    ans.push_back(str[j++]);
                }
                else{
                    ans.push_back(s[i++]);
                }
            }
        }
        
        while(i<n){
            ans.push_back(s[i++]);
        }
        while(j<m){
            ans.push_back(str[j++]);
        }
        return ans;
    }
};
















