// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int minDeletions(string str, int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << minDeletions(s, n) << endl;

    }
return 0;
}// } Driver Code Ends

string lcs(string s, string str, int n){
    vector<vector<int>>dp(n+1,vector<int>(n+1));
    
    for(int i=1; i<n+1; i++){
        for(int j=1; j<n+1; j++){
            if(s[i-1]==str[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    int i=n,j=n;
    string x="";
    while(i>0 and j>0){
        if(s[i-1]==str[j-1]){
            x.push_back(s[i]);
            i--;j--;
        }
        else{
            if(dp[i-1][j]>dp[i][j-1]) i--;
            else j--;
        }
    }
    return x;
}
int minDeletions(string str, int n) { 
    //complete the function here 
    
    string s=str;
    reverse(str.begin(), str.end());
    string x=lcs(s, str, n);
    int len = n-x.size();
    return len;
} 