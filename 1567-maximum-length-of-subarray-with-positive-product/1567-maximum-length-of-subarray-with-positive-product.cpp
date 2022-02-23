class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0; i<n; i++){
            while(nums[i]==0 and i<n)i++;
            int strt=i,end=i,negStrt=-1,negEnd=-1;
            int cnt=0;
            while(end<n and nums[end]!=0){
                if(nums[end]<0){
                    cnt++;
                    if(negStrt==-1) negStrt=end;
                    negEnd=end;
                }
                
                if(cnt%2==0){
                    ans=max(ans,end-strt+1);
                }
                else{
                    if(negStrt!=-1){
                        ans=max(ans,end-negStrt);
                    }
                    if(negEnd!=-1){
                        ans=max(ans,negEnd-strt);
                    }
                }
                end++;
            }
            i=end;
        }
        return ans;
    }
};