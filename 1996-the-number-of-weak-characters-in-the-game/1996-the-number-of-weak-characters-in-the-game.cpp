class Solution {
public:
    static bool cmp(vector<int>&a, vector<int>&b){
        if(a[0]==b[0]){
            return a[1]<b[1];
        }
        return a[0]>b[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(),properties.end(),cmp);
        // for(auto i:properties){
        //     cout<<"["<<i[0]<<" "<<i[1]<<"]"<<"  ";
        // }
        // cout<<endl;
        int cnt=0;
        int mini=properties[0][1];
        for(int i=1; i<properties.size(); i++){
            if(properties[i][1]<mini){
                cnt++;
                //cout<<i<<" ";
            } 
            mini = max(mini,properties[i][1]);
        }
        return cnt;
    }
};