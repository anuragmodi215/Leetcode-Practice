class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int,int>inDegree;
        unordered_map<int,int>outDegree;
        int m = trust.size();
        if(n==1 and m==0) return 1;
        for(int i=0; i<m; i++){
            inDegree[trust[i][1]]++;
            outDegree[trust[i][0]]++;
        }
        for(auto in: inDegree){
            if(in.second==n-1){
                if(outDegree.find(in.first)==outDegree.end()){
                    return in.first;
                }
            }
        }
        return -1;
    }
};