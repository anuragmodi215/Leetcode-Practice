class Solution {
public:
    vector<int> frequencySort(vector<int>& a) {
        unordered_map<int,int>mp;
        int n = a.size();
        for(int i=0; i<n; i++){
            mp[a[i]]++;
        }
      sort(a.begin(),a.end(),[&](int x, int y){
          return mp[x] != mp[y]? mp[x] < mp[y] :x>y;});
      return a;
    }
};