class Solution {
public:
    bool isValid(int dx, int dy, vector<vector<int>>&distance){
        int n = distance.size();
        int m = distance[0].size();
        if(dx<n and dy<m and dx>=0 and dy>=0 and distance[dx][dy]==-1)return true;
        else return false;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>distance(n,vector<int>(m,-1));
        queue<pair<int,int>>q;
        vector<pair<int,int>>dir{{1,0},{-1,0},{0,1},{0,-1}};
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    distance[i][j]=0;
                }
            }
        }
        
        while(!q.empty()){
            pair<int,int>coord = q.front();
            int x = coord.first;
            int y = coord.second;
            q.pop();
            for(auto i:dir){
                int dx = x+i.first;
                int dy = y+i.second;
                if(isValid(dx,dy,distance)){
                    distance[dx][dy] = distance[x][y]+1;
                    q.push({dx,dy});
                }
            }
        }
        return distance;
    }
};