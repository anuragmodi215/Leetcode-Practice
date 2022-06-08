class Solution {
public:
    vector<pair<int,int>>dir{{1,0},{0,1},{-1,0},{0,-1}};
    bool isValid(int i, int j, int index, vector<vector<char>>& board, string&word){
        int n = board.size();
        int m = board[0].size();
        if(i<n and j<m and i>=0 and j>=0 and board[i][j]==word[index]){
            return true;
        }
        return false;
    }
    bool dfs(int i, int j, int index,vector<vector<char>>& board,string &word){
        if(index==word.size()) return true;

        for(int k=0; k<4; k++){
            if(isValid(i,j,index,board,word)){  
                board[i][j]='*';
                int dx = i+dir[k].first;
                int dy = j+dir[k].second;
                bool validity = dfs(dx,dy,index+1,board,word);
                if(validity) return true;
                board[i][j]=word[index];
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                bool x = dfs(i,j,0,board,word);
                if(x) return true;
            }
        }
        return false;
    }
};