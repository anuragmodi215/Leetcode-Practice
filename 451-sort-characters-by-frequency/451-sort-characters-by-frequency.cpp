class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>freq;
        vector<vector<int>>v(s.size()+1);
        for(int i=0; i<s.size(); i++){
            freq[s[i]]++;
        }
        for(auto i:freq){
            char c = i.first;
            int cnt = i.second;
            
            v[cnt].push_back(c);
        }
        
        string ans="";
        for(int i=v.size()-1; i>=0; i--){
            if(v[i].size()>0){
                int times=i;
                for(int j = 0; j<v[i].size(); j++){
                    for(int k=0; k<times; k++)
                        ans.push_back(v[i][j]);
                }
            }
        }
        return ans;
    }
};