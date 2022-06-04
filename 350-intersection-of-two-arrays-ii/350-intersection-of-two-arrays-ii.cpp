class Solution {
public:
    vector<int> intersect(vector<int>& first, vector<int>& second) {
        unordered_map<int,int>mp;
        for(int i=0; i<second.size(); i++){
            mp[second[i]]++;
        }
        vector<int>ans;
        int n = first.size();
        for(int i=0; i<n; i++){
            if(mp.find(first[i])!=mp.end()){
                ans.push_back(first[i]);
                mp[first[i]]--;
                if(mp[first[i]]==0){
                    mp.erase(first[i]);
                }
            }
        }
        return ans;
    }
};