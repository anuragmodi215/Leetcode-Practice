class Solution {
public:
    int pivotIndex(vector<int>& v) {
        
        int sum=0;
        for(auto i:v)
            sum = sum+i;
        
        int left=0;
        
        for(int i=0; i<v.size(); i++){
             sum = sum-v[i];
            if(sum==left)
                return i;
           // else if(left>sum) break;
            
            else{
                left = left+v[i];
              
            }
        }
        
        return -1;
    }
};