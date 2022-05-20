class Solution {
public:
    int dx[4]={1,0,-1,0};
    int dy[4]={0,-1,0,1};
    bool isValid(int i, int j, vector<vector<int>>& image, vector<vector<int>>&visited, int colour,int newColor){
        int n = image.size();
        int m = image[0].size();
        if(i<n and j<m and i>=0 and j>=0 and !visited[i][j] and image[i][j]==colour)return true;
        return false;
    }
    void dfs(int i, int j, vector<vector<int>>& image, vector<vector<int>>&visited, int colour,int newColor){
        for(int k=0; k<4; k++){
            int x = dx[k]+i;
            int y = dy[k]+j;
            image[i][j]=newColor;
            if(isValid(x,y,image,visited,colour,newColor)){
                visited[x][y]=1;
                dfs(x,y,image,visited,colour,newColor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        dfs(sr,sc,image,visited,image[sr][sc],newColor);
        //image[sr][sc] = newColor;
        return image;
    }
};