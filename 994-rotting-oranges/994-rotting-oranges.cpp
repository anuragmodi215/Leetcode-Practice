class Solution {
public:
    bool isValid(int dx, int dy, vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        if(dx<n and dy<m and dx>=0 and dy>=0 and grid[dx][dy]==1){
            return true;
        }
        return false;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<vector<int>>q;
        int n = grid.size();
        int m = grid[0].size();
        int orange=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==2){
                    q.push({i,j,0});
                }
                if(grid[i][j]!=0){
                    orange++;
                }
            }
        }
        
        vector<pair<int,int>>dir{{1,0},{0,1},{-1,0},{0,-1}};
        int maxTime = 0;
        int cnt=0;
        while(!q.empty()){
            int x = q.front()[0];
            int y = q.front()[1];
            int time = q.front()[2];
            //cout<<x<<" "<<y<<" "<<time<<endl;
            q.pop();
            cnt++;
            maxTime = max(time,maxTime);
            for(auto i:dir){
                int dx = x+i.first;
                int dy = y+i.second;
                if(isValid(dx,dy,grid)){
                    grid[dx][dy]=2;
                    q.push({dx,dy,time+1});
                }
            }
        }
        if(cnt==orange){
            return maxTime;
        }
        return -1;
    }
};