class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& a) {
        int row = a.size();
        int cols = a[0].size();
        
        int left = 0;
        int right = cols-1;
        int top = 0;
        int bottom = row-1;
        int d=0;
        vector<int>v;
        while(left<=right and top <= bottom){
            if(d==0){
            for(int i=left; i<=right; i++){
                v.push_back(a[top][i]);

            }
                top++;
                d=1;
            }
            else if(d==1){
            for(int i=top; i<=bottom; i++){
                v.push_back(a[i][right]);
            }
                 right--;
                d=2;
            }
            else if(d==2){
            for(int i = right; i>=left; i--){
                v.push_back(a[bottom][i]);           
            }
                 bottom--;
                d=3;
            }
            else if(d==3){
            for(int i=bottom; i>=top;i--){
                v.push_back(a[i][left]);             
            }
                left++;
                d=0;
            }
        }
        return v;
    }
};