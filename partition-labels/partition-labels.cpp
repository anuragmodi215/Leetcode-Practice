class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>lastOccurence;
        int n=s.size();
        for(int i=0; i<n; i++){
            lastOccurence[s[i]]=i;
        }
        int i=0,j=0;
        int lastMax=0;
        vector<int>ans;
        while(i<n and j<n){
            lastMax=max(lastMax,lastOccurence[s[j]]);
            if(j<lastMax){
                j++;
            }
            else{
                ans.push_back(j-i+1);
                i=j+1;j++;
            }
        }
        return ans;
    }
};