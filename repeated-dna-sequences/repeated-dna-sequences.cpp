class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int>mp;
        vector<string>ans;
        int n=s.size();
        if(n<10) return ans;
        int len=n-9;
        for(int i=0; i<len; i++){
            mp[s.substr(i,10)]++;
        }
        for(auto i: mp){
            if(i.second>1) ans.push_back(i.first);
        }
        return ans;
    }
};