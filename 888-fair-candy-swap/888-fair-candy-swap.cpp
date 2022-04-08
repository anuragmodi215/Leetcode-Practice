class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int sa=0,sb=0;
        unordered_set<int>set; vector<int>ans(2);
        for(auto x:aliceSizes) sa+=x;
        for(auto x: bobSizes) sb+=x;
        
        int delta = (sa-sb)/2;
        
        for(auto a: aliceSizes){
            set.insert(a);
        }
        
        for(auto b: bobSizes){
            if(set.find(b+delta)!=set.end()){
               ans[1]=b; ans[0] = b+delta;
                return ans;
            }
        }
        return ans;
    }
};