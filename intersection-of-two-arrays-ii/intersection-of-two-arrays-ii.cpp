class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int n=nums1.size();
        int n2=nums2.size();
        int i=0,j=0;
        vector<int>v;
        while(i<n and j<n2){
           if(nums1[i]==nums2[j]){
               v.push_back(nums1[i]); //v.push_back(nums2[j]);
               i++;j++;
           } 
           else if(nums1[i]>nums2[j]){
               j++;
           }
            else i++;
        }
        return v;
    }
};