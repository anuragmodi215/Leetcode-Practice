class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>mp;
        int maxFreq=0;
        for(int i=0; i<tasks.size(); i++){
            mp[tasks[i]]++;
            maxFreq = max(maxFreq,mp[tasks[i]]);
        }
        
        int ans = (maxFreq-1)*(n+1);
        for(auto c:mp){
            if(c.second==maxFreq)ans++;
        }
        //cout<<tasks.size();
        return max(ans,(int)tasks.size());
    }
};