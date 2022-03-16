class Solution {
public:
    //private:
    static bool cmp(vector<int>&a, vector<int>&b){
        return a[1]<b[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),cmp);
        
        int n=pairs.size();
        int cnt=1;
        vector<int>prevPair;
        prevPair.push_back(pairs[0][0]);
        prevPair.push_back(pairs[0][1]);
        for(int i=1; i<n; i++){
            
            if(prevPair[1]<pairs[i][0]){
                
                prevPair[0]=(pairs[i][0]);
                prevPair[1]=(pairs[i][1]);
                cnt++;
            } 
        }
        return cnt;
    }
};