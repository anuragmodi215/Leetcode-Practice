class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        unordered_map<int,vector<pair<int,double>>>adj;
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back({v,succProb[i]});
            adj[v].push_back({u,succProb[i]});
        }
        // for(auto i:adj){
        //     cout<<i.first<<"->";
        //     for(auto j:i.second){
        //         cout<<'['<<j.first<<','<<j.second<<']'<<" ";
        //     }
        //     cout<<endl;
        // }
        
        priority_queue<pair<double,int>>pq;
        pq.push({(double)(1.0),start});
        vector<double>maxProb(n,0.0);
        maxProb[start] = 1.0;
        while(!pq.empty()){
            int frontNode = pq.top().second;
            double prob = pq.top().first;
            //cout<<prob<<" "<<frontNode<<endl;
            pq.pop();
            for(auto neig: adj[frontNode]){
                int nextNode = neig.first;
                double nextProb = neig.second;
                //cout<<nextProb<<endl;
                if(maxProb[nextNode]<prob*nextProb){
                    maxProb[nextNode]=prob*nextProb;
                    pq.push({maxProb[nextNode],neig.first});
                }
            }
        }
        return maxProb[end];
    }
};