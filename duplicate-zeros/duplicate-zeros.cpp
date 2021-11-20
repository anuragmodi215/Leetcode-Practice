class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        
        int n = arr.size();
        int i=n-1;
        int cnt=0;
        for(auto i: arr) if(i==0) cnt++;
        if(cnt==0) return;
        int j=arr.size()+cnt-1;
        cout<<j;
        while(i>=0 and j>=0){
            if(i==j) return;
            if(arr[i]==0){
                if(j>=n){
                    j--;
                    if(j<n) arr[j]=arr[i];
                }
                else{
                    arr[j]=arr[i];
                    j--;
                    if(j>=0)
                    arr[j]=arr[i];
                }
            }
            else{
                if(j<n){
                    arr[j] = arr[i];
                }
            }
            j--;i--;            
        }
        
    }
};