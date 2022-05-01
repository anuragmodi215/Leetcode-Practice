class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0; i<n; i++){
            int slow = matrix[i][0];
            int fast = matrix[i][m-1];
            
            if(fast>=target){
                if(binary_search(matrix[i].begin(), matrix[i].end(),target)){
                    return true;
                }
                else return false;
            }
        }
        return false;
    }
};