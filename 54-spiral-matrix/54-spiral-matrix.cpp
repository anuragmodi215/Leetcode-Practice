class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>v;
        int n = matrix.size();
        int m = matrix[0].size();
        int left=0,right=m-1,bottom=n-1,top=0;
        int dir=1;
        while(left<=right and top<=bottom){
            if(dir==1){
                for(int i=left; i<=right; i++){
                    v.push_back(matrix[top][i]);
                }
                top++;
                dir=2;
            }
            else if(dir==2){
                //cout<<top<<" "<<right<<endl;
                for(int i=top; i<=bottom; i++){
                    //cout<<matrix[i][right]<<" ";
                    v.push_back(matrix[i][right]);
                }
                right--;
                dir=3;
            }
            else if(dir==3){
                for(int i=right; i>=left; i--){
                    v.push_back(matrix[bottom][i]);
                }
                bottom--;
                dir=4;
            }
            else if(dir==4){
                for(int i=bottom; i>=top; i--){
                    v.push_back(matrix[i][left]);
                }
                left++;
                dir=1;
            }
        }
        return v;
    }
};