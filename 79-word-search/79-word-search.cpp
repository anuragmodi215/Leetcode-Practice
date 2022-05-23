class Solution {
public:
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    bool isValid(int x, int y, int index,vector<vector<char>>& board, string &word){
        int n = board.size();
        int m = board[0].size();
        if(x>=0 and x<n and y>=0 and y<m  and word[index]==board[x][y]) 
            return true;
        else return false;
    }
    bool dfs(int i, int j,int index,vector<vector<char>>& board,string &word){
        if(index == word.size()) return true;
        
        for(int k=0; k<4; k++){
            if(isValid(i,j,index,board,word)){
                board[i][j]='*';
                int x = i+dx[k];
                int y = j+dy[k];
                bool validity = dfs(x,y,index+1,board,word);
                if(validity) return true;
                board[i][j] = word[index];
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        //vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                bool x = dfs(i,j,0,board,word);
                if(x) return true;
            }
        }
        return false;
    }
};