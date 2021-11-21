class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int,int>mp;
        
        for(auto &i:arr){
            if(i%2==0 and mp.find(i/2) != mp.end() or mp.find(2*i)!=mp.end()) return true;
            else mp[i]++;
        }
        return false;
    }
};