class Solution {
public:
    string helper(string s, string str, int n, int m){
        vector<vector<int>>dp(n+1, vector<int>(m+1));
        string sequence="";
        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                if(s[i-1]==str[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        int i=n,j=m;
        while(i>0 and j>0){
            if(s[i-1]==str[j-1]){
                sequence.push_back(s[i-1]);
                i--;j--;
            }
            else{
                if(dp[i-1][j]>dp[i][j-1]) i--;
                else j--;
            }
        }
        
        reverse(sequence.begin(),sequence.end());
        return sequence;
    }
    int minDistance(string s, string str) {
        int n=s.size();
        int m=str.size();
        string sequence=helper(s,str,n,m);
        cout<<sequence<<endl;
        int i=0,j=0,k=0;
        int o=sequence.size();
        int cnt=0;
        
        while(i<n and j<m and k<o){
            if(s[i]==str[j] and s[i]==sequence[k]){
                i++;j++;k++;
            }
            else{
                if(s[i]==sequence[k]){
                    j++;
                    cnt++;
                }
                else{
                    i++; cnt++;
                }
            }
        }
        cnt=cnt+(n-i);
        cnt=cnt+(m-j);
        return cnt;
        // while(i<n){
        //     cnt++;
        //     i++;
        // }
        // while(j<m){
        //     cnt++;
        //     j++;
        // }
        //return cnt;
    }
};













