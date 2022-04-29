class Solution {
public:
    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
        int i=n-1,j=m-1;
        int index = n+m-1;
        
        while(i>=0 and j>=0){
            if(nums1[i]>=nums2[j]){
                nums1[index--]=nums1[i--];
            }
            else{
                nums1[index--]=nums2[j--];
            }
        }
        while(i>=0){
            nums1[index--]=nums1[i--];
        }
        while(j>=0){
            nums1[index--]=nums2[j--];
        }
    }
};