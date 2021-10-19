class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int>s;
        for(int i=0; i<nums1.size(); i++){
            s.insert(nums1[i]);
        }
        set<int>s2;
        for(int i=0; i<nums2.size(); i++){
            if(s.find(nums2[i])!=s.end()){
                s2.insert(nums2[i]);
            }
        }
        vector<int>v;
        for(auto i:s2) v.push_back(i);
        return v;
    }
};