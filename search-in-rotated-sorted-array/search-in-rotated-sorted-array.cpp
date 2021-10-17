class Solution {
public:
    int minInd(vector<int>a, int n, int x){
        int strt=0,end=n-1,prev,next,mid=0;
        
        while(strt<=end){
            mid=strt+((end-strt)/2);
             
            prev=abs((mid-1)%n);
            next=abs((mid+1)%n);
            // prev=(mid-1)%n;
            // next=(mid+1)%n;
           
            cout<<a[mid]<<endl;
            if(a[mid]<a[prev] and a[mid]<a[next]) return mid;
            else if(a[mid]>a[end]) strt=mid+1;
            else end=mid-1;
        }
        return mid;
    }
    int bs(vector<int>a,int strt,int end,int x){
        int mid;
        while(strt<=end){
            mid=strt+((end-strt)/2);
            if(a[mid]==x) return mid;
            
            else if(a[mid]>x) end = mid-1;
            else strt=mid+1;
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int ind=0;
        //if(nums[0]>nums[n-1])
        ind=minInd(nums,n,target);
        
        //cout<<"ind:"<<ind<<endl;
        
        int check1=bs(nums,0,ind-1,target);
        if(check1 == -1){
            int check2=bs(nums,ind,n-1,target);
            return check2;
        }
        return check1;
        
        
    }
};








