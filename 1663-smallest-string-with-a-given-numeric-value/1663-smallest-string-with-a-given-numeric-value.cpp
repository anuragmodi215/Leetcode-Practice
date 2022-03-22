class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans="";
        int j=n-1;
        for(int i=0; i<n; i++){
            ans+='a';
        }
        k=k-n;
        while(k>0 and j>=0){
            if(k>25){
                ans[j--]='z';
                k=k-25;
            }
            else{
                ans[j--]=('a'+k);
                break;
            }
        }
        
        return ans;
    }
};