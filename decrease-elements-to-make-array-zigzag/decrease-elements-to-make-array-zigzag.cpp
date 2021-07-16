class Solution {
public:
    int movesToMakeZigzag(vector<int>& a) {
        int n=a.size();
        int c1=0, c2=0;
        //make odd index small
        
        if(n<=1) return 0;
        for(int i=1; i<n; i=i+2){
            if(i==n-1){
                if(a[i]>=a[i-1]){
                    c1 = c1+a[i]-a[i-1]+1;
                }
            }
            else{
                if(a[i]>=a[i-1] or a[i]>=a[i+1]){
                    c1 = c1+a[i]-min(a[i+1],a[i-1])+1;
                }
            }
        }
        
        //make even small
        
        for(int i=0; i<n; i= i+2){
            if(i==0){
                if(a[i]>=a[i+1]){
                    c2 = c2+a[i]-a[i+1]+1;
                }
            }
            else if(i==n-1){
                if(a[i]>=a[i-1]){
                    c2 = c2+a[i]-a[i-1]+1;
                }
            }
            else{
                if(a[i]>=a[i-1] or a[i]>=a[i+1]){
                    c2 = c2+a[i]-min(a[i+1],a[i-1])+1;
                }
            }
        }
        
        return min(c1,c2);
    }
};