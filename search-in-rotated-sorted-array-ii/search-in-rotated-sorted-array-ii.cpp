class Solution {
public:
    int minInd(vector<int>a, int n, int x){
        int max=a[0];
        int maxInd=0;
        for(int i=1; i<n; i++){
            if(a[i-1]>a[i])break;
            if(a[i]>=max){
                max=a[i];
                maxInd=i;
            }
        }
        return maxInd;
    }
    
    bool bs(vector<int>a,int strt,int end,int x){
        int mid;
        while(strt<=end){
            mid=strt+((end-strt)/2);
            if(a[mid]==x) return true;
            
            else if(a[mid]>x) end = mid-1;
            else strt=mid+1;
        }
        return false;
    }
    
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int ind=0;
        //if(nums[0]>nums[n-1])
        ind=minInd(nums,n,target);
        cout<<"ind:"<<ind<<endl;
        
        bool check1=bs(nums,0,ind,target);
        if(!check1){
            bool check2=bs(nums,ind+1,n-1,target);
            return check2;
        }
        return check1;
    }
};