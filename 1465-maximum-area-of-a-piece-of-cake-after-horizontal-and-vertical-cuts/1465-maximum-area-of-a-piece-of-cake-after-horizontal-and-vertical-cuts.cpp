class Solution {
public:
    int maxArea(int h, int w, vector<int>& hCuts, vector<int>& vCuts) {
        
        hCuts.push_back(0);
        hCuts.push_back(h);
        vCuts.push_back(0);
        vCuts.push_back(w);
        sort(hCuts.begin(),hCuts.end());
        sort(vCuts.begin(),vCuts.end());
        int length=0;
        int breadth=0;
        for(int i=1; i<hCuts.size(); i++){
            breadth = max(breadth,hCuts[i]-hCuts[i-1]);
        }
        for(int i=1; i<vCuts.size(); i++){
            length = max(length,vCuts[i]-vCuts[i-1]);
        }
        int mod =(int)1e9+7;
        return ((long long int)breadth*(long long int)length)%mod;
    }
};