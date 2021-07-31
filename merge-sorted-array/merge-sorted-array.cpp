class Solution {
public:
    void merge(vector<int>& a, int m, vector<int>& b, int n) {
        
        int i=m-1;
        int j=n-1;
        int full = m+n-1;
        
        while(i>=0 and j>=0){
        if(a[i] > b[j]){
            a[full]=a[i];
            a[i]=0;
            full--;
            i--;
        }
        // else if(b[j]>a[i]){
            else{
            a[full] = b[j];
            b[j]=0;
            full--;
            j--;
        }
        }
        
        while(i>=0){
            a[full] = a[i];
            i--; full--;
        }
        while(j>=0){
            a[full] = b[j];
            j--; full--;
        }
    }
};