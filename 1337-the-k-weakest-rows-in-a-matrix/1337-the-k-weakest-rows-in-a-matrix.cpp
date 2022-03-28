class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m=mat.size();
        int n=mat[0].size();
        
        vector<int>ans;
        priority_queue<pair<int,int>>pq;
        
        for(int i=0; i<m; i++){
            pair<int,int>cnt={0,0};
            for(int j=0; j<n; j++){
                if(mat[i][j]==1) cnt.first++;
            }
            cnt.second=i;
            cout<<cnt.first<<" "<<cnt.second<<endl;
            pq.push(cnt);
            if(pq.size()>k)pq.pop();
        }
        
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};