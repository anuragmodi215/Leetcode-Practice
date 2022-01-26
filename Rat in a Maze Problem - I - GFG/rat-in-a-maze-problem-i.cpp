// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void helper(vector<vector<int>> &m,int end, string s, vector<vector<int>>&visited,vector<string>&ans,int row, int col){
        if(row==end-1 and col==end-1){
            ans.push_back(s);
            return;
        }
        if(row+1<end and m[row+1][col]==1 and !visited[row+1][col]){
            s.push_back('D');
            visited[row][col]=1;
            helper(m,end,s,visited,ans,row+1,col);
            s.pop_back();
            visited[row][col]=0;
        }
        if(col-1>=0 and m[row][col-1]==1 and !visited[row][col-1]){
            s.push_back('L');
            visited[row][col]=1;
            helper(m,end,s,visited,ans,row,col-1);
            s.pop_back();
            visited[row][col]=0;
        }
        if(col+1<end and m[row][col+1]==1 and !visited[row][col+1]){
            s.push_back('R');
            visited[row][col]=1;
            helper(m,end,s,visited,ans,row,col+1);
            s.pop_back();
            visited[row][col]=0;
        }
        if(row-1>=0 and m[row-1][col]==1 and !visited[row-1][col]){
            s.push_back('U');
            visited[row][col]=1;
            helper(m,end,s,visited,ans,row-1,col);
            s.pop_back();
            visited[row][col]=0;
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<vector<int>> visited(n,vector<int>(n,0));
        vector<string>ans;
        if(m[0][0]==1)
        helper(m,n,"",visited,ans,0,0);
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends