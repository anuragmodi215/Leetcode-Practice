class Solution {
public:
    int majorityElement(vector<int>& a) {
        unordered_map<int,int>m;
        for(int i=0; i<a.size(); i++){
            m[a[i]]++;
            if(m[a[i]]> a.size()/2){
                return a[i];
            }
        }
        return -1;
    }
};