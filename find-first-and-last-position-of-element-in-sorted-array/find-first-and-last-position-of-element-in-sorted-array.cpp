class Solution {
public:
    int firstOccurence(vector<int>a,int n, int x){
        int strt=0,end =n-1,res=-1;
        int mid;
        while(strt<=end){
            mid = strt+((end-strt)/2);
            if(a[mid]==x){
                res=mid; end=mid-1;
            }
            else if(x<a[mid])end=mid-1;
            else strt=mid+1;
        }
        return res;
    }
    int lastOccurence(vector<int>a,int n, int x){
        int strt=0,end =n-1,res=-1;
        int mid;
        while(strt<=end){
            mid = strt+((end-strt)/2);
            if(a[mid]==x){
                res=mid; strt=mid+1;
            }
            else if(x<a[mid])end=mid-1;
            else strt=mid+1;
        }
        return res;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>v;
        int n = nums.size();
        if(n==0){
            v.push_back(-1);
            v.push_back(-1);
            return v;
        }
        int first=firstOccurence(nums,n,target);
        int last=lastOccurence(nums,n,target);
        v.push_back(first);
        v.push_back(last);
        return v;
    }
};