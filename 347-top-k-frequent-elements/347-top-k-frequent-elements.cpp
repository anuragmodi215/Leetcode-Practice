class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mp;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        vector<int>ans;
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }
        
        for(auto i:mp){
            pq.push({i.second,i.first});
            if(pq.size()>k){
                pq.pop();
            }
        }
        //vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};