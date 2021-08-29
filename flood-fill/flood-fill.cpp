class Solution {
public:
    void solve(vector<vector<int>>& image, int sr, int sc, int newColor,int rows,int cols,int source)
    {
        if(sr<0 or sr>=rows or sc<0 or sc>=cols) return;
        
        else if(image[sr][sc] != source) return;
        
        image[sr][sc] = newColor;
        solve(image,sr+1,sc,newColor,rows,cols,source);//down
        solve(image,sr,sc+1,newColor,rows,cols,source);//right
        solve(image,sr-1,sc,newColor,rows,cols,source);//up
        solve(image,sr,sc-1,newColor,rows,cols,source);//left
        
    }
    
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
     if(image[sr][sc]==newColor) return image;
     int source = image[sr][sc];
     int rows = image.size();
     int cols = image[0].size();
        solve(image,sr,sc,newColor,rows,cols,source);
        return image;
    }
};