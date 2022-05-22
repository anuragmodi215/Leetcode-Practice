class Solution {
public:
    static bool cmp(vector<int>&a, vector<int>&b){
        int x = a[0]-a[1];
        int y = b[0]-b[1];
        return x<y;
    }
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int cnt=0;
        int n = capacity.size();
        vector<vector<int>>v(n,vector<int>(2));
        for(int i=0; i<n; i++){
            v[i][0] = capacity[i];
            v[i][1] = rocks[i];
        }
        sort(v.begin(),v.end(),cmp);
        // for(int i=0; i<n; i++){
        //     cout<<v[i][0]<<" "<<v[i][1]<<endl;
        // }
        
        for(int i=0; i<n; i++){
            if(v[i][0]==v[i][1]){
                cnt++;
                continue;
            }
            else{
                if(additionalRocks>=v[i][0]-v[i][1]){
                    cnt++;
                    additionalRocks = additionalRocks-(v[i][0]-v[i][1]);
                }
                else break;
            }
        }
        
        return cnt;
    }
};