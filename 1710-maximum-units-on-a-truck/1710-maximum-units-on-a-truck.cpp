class Solution {
public:
    static bool myfun(vector<int>&a, vector<int>&b){
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& box, int truckSize) {
        sort(box.begin(),box.end(),myfun);
        
        int n=box.size();
        int ans=0;
        
        for(int i=0; i<n; i++){
            if(box[i][0]<=truckSize){
                ans+=box[i][0]*box[i][1];
                
                truckSize-=box[i][0];
                if(truckSize<=0)break;
            }
            else {
                ans+=truckSize*box[i][1];
                truckSize-=box[i][0];
                if(truckSize<=0)break;
            }
        }
        return ans;
    }
};