class Solution {
public:
    vector<int> topKFrequent(vector<int>& a, int k) {
        unordered_map<int,int>mp;
        int n = a.size();
        for(int i=0; i<n; i++){
            mp[a[i]]++;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        for(auto i=mp.begin(); i!=mp.end(); i++){
            pq.push({i->second,i->first});
            if(pq.size()>k){
                pq.pop();
            }
        }
    vector<int>v;
        while(!pq.empty()){
         v.push_back(pq.top().second);
         pq.pop();
        }
        return v;
    }
};