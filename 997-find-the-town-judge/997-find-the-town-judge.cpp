class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int,int>inOut;
        int m = trust.size();
        if(m==0 and n==1)return 1;
        for(int i=0; i<m; i++){
            inOut[trust[i][1]]++;
            inOut[trust[i][0]]--;
        }
        for(auto i:inOut){
            if(i.second==n-1) return i.first;
        }
        return -1;
    }
};