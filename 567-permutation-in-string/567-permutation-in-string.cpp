class Solution {
public:
    bool checkInclusion(string s, string str) {
        if(s.size()>str.size()) return false;
        unordered_map<char,int>check;
        unordered_map<char,int>comp;
        int n=str.size();
        for(auto &i:s) check[i]++;
        
        int i=0;
        int j=0;
        while(j<n){
            if(j-i+1<=s.size()){
                comp[str[j]]++;
                j++;
                
                if(comp==check) return true;
            }
            
            else{
                     comp[str[i]]--;
                    if(comp[str[i]]==0) comp.erase(str[i]);
                        i++;
                }
            }            
        
        return false;
    }
};