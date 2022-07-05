class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int k = p.size();
        unordered_map<char,int>parent;
        unordered_map<char,int>child;
        vector<int>ans;
        for(auto i:p){
            parent[i]++;
        }
        int i=0;
        int j=0;
        int n = s.size();
        while(j<n){
            if(j-i+1<k){
                child[s[j]]++;
                j++;
            }
            else{
                child[s[j]]++;
                if(parent==child){
                    ans.push_back(i);
                }
                child[s[i]]--;
                if(child[s[i]]==0){
                    child.erase(s[i]);
                }
                i++;j++;
            }
        }
        
        return ans;
    }
};