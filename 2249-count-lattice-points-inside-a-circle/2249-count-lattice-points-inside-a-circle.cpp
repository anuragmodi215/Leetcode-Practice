class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        set<pair<int,int>>set;
        int n=circles.size();
        for(int k=0; k<n; k++){
            int x = circles[k][0];
            int y = circles[k][1];
            int r = circles[k][2];
            
            for(int i = x-r; i<=x+r; i++){
                for(int j = y-r; j<=y+r; j++){
                    if((i-x)*(i-x)+(j-y)*(j-y)<=r*r){
                        set.insert({i,j});
                    }
                }
            }
        }
        return set.size();
    }
};