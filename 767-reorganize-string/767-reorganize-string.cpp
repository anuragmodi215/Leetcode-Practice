class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int,char>>pq;
        unordered_map<char,int>mp;
        string ans ="";
        int n = s.size();
        int maxFreq=0;
        for(int i=0; i<n; i++){
            mp[s[i]]++;
            maxFreq = max(maxFreq,mp[s[i]]);
        }
        if(maxFreq>(n+1)/2) return "";
        for(auto i:mp){
            pq.push({i.second,i.first});
        }
        while(!pq.empty()){
            char ch=pq.top().second;
            int times = pq.top().first;
            //cout<<ch<<" "<<times<<endl;
            pq.pop();
            ans+=ch;
            times--;
            int times2;
            char ch2;
            if(!pq.empty()){
                ch2 = pq.top().second;
                times2 = pq.top().first;
                pq.pop();
                times2--;
                ans+=ch2;
                if(times2>0){
                    pq.push({times2,ch2});
                }
            }
            if(times>0){
                pq.push({times,ch});
            }
        }
        return ans;
    }
};