class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int top,left,right,bottom;
        top=0;
        left=0;
        right=n-1;
        bottom=m-1;
        vector<int>v;
        int i=0,j=0;
        int k=1;
        while(left<=right and top<=bottom){
            if(k==1){
               for(int i=left; i<=right; i++)
                   v.push_back(matrix[top][i]);
                top++; k=2;
            }
            else if(k==2){
                for(int i=top; i<=bottom; i++)
                   v.push_back(matrix[i][right]);
                right--; k=3;
                
            } 
            else if(k==3){
              for(int i=right; i>=left; i--)
                  v.push_back(matrix[bottom][i]);
                  bottom--;k=4;
            }
            else if(k==4){
               for(int i=bottom; i>=top; i--)
                   v.push_back(matrix[i][left]);
                left++; k=1;
            }
        }
        return v;
    }
};