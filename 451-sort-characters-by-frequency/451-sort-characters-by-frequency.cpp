class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        vector<pair<int,char>>v;
        int n = s.size();
        for(int i=0; i<n; i++){
            mp[s[i]]++;
        }
        for(auto i:mp){
            v.push_back({i.second,i.first});
        }
        sort(v.begin(),v.end(),greater<pair<int,char>>());
        string t = "";
        for(int i=0; i<v.size(); i++){
            int times = v[i].first;
            for(int j=0; j<times; j++){
                t+=v[i].second;
            }
        }
        return t;
    }
};