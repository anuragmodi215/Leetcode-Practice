class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        vector<int>freq;
        
        for(int i=1; i<n; i++){
            int cnt=1;
            int j;
            for( j=i; j<n; j++){
                if(arr[j]==arr[j-1]){
                    cnt++;
                }
                else break;
            }
            freq.push_back(cnt);
            i=j;
        }
        sort(freq.begin(),freq.end());
        int cnt=0;
        int removed = 0;
        for(int i=freq.size()-1; i>=0 ;i--){
            if(removed<n/2){
                removed+=freq[i];
                cnt++;
            }
            else{
                break;
            }
        }
        return cnt;
    }
};

