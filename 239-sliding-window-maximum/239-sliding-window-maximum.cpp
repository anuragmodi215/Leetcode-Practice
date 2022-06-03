class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        int maxInd=0;
        int secondMaxInd=0;
        int i=0,j=0;
        vector<int>ans;
        priority_queue<pair<int,int>>pq;
        while(j<n){
            pq.push({nums[j],j});
            if(j-i+1<k){
                j++;
            }
            else if(j-i+1==k){
                pq.push({nums[j],j});
                while(pq.top().second<i){
                    pq.pop();
                }
                ans.push_back(pq.top().first);
                i++;j++;
            }
        }
        return ans;
    }
};