// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<vector<int>>dir{
        {1,0},{0,-1},{0,1},{-1,0}
    };
    vector<char>path{'D','L','R','U'};
    void helper(vector<vector<int>> &m, int n, int row, int col, string s, vector<string>&ans,vector<vector<int>>&visited){
        //cout<<row<<" "<<col<<endl;
        if(col==n-1 and row==n-1){
            ans.push_back(s);
            return;
        }
        for(int i=0; i<4; i++){
            int nx = row+dir[i][0];
            int ny = col+dir[i][1];
            if(nx<n and ny<n and nx>=0 and ny>=0 and !visited[nx][ny] and m[nx][ny]==1){
                visited[row][col]=1;
                helper(m,n,nx,ny,s+path[i],ans,visited);
                visited[row][col]=0;
            }
        }
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        vector<vector<int>> visited(n,vector<int>(n,0));
        if(m[0][0]==1){
            helper(m,n,0,0,"",ans,visited);
        }
        
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