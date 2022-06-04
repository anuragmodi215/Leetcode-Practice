class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& str) {
        
        vector<vector<string>>ans;
        int n = str.size();
        unordered_map<string,vector<string>>mp;
        for(int i=0; i<n; i++){
            string key = str[i];
            sort(key.begin(),key.end());
            mp[key].push_back(str[i]);
        }
        for(auto i:mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};