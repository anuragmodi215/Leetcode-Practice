class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int n1=firstList.size();
        int n2=secondList.size();
        vector<vector<int>> ans;
        if(n1==0 or n2==0) return ans;
        int i=0,j=0;
        while(i<n1 and j<n2){
            int strt=max(firstList[i][0],secondList[j][0]);
            int ending=min(firstList[i][1],secondList[j][1]);
            vector<int>temp(2,0);
            if(strt<=ending){
            temp[0]=strt;
            temp[1]=ending;           
            ans.push_back(temp);
            }
            
            if(firstList[i][1]<secondList[j][1]){
                //cout<<firstList[i+1][0];
                i++;
            }
            else
                j++;
            
        }
        return ans;
    }
};









