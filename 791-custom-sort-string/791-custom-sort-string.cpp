class Solution {
public:
    string customSortString(string order, string s) {
        int n=order.size();
        map<int,char>ord;
        map<char,int>freq;
        string ans="";
        for(int i=0; i<n; i++){
            ord[i]=order[i];
        }
        n=s.size();
        for(int i=0; i<n; i++){
            freq[s[i]]++;
        }
        
        for(auto i:ord){
            if(freq.find(i.second)!=freq.end()){
                int times=freq[i.second];
                for(int j=0; j<times; j++){
                    //auto x=i.second;
                    ans.push_back(i.second);
                    freq[i.second]--;
                    if(freq[i.second]==0) freq.erase(i.second);
                }
            }
        }
        for(auto i:freq){
            int times=i.second;
           // cout<<
            for(int j=0; j<times; j++){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};