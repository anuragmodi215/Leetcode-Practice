class Solution {
public:
    int thirdMax(vector<int>& nums) {
        //prioroty_queue<int, vector<int>, greater<int>> pq;
        int n=nums.size();
        set<int>set;
        for(int i=0; i<n; i++){
            set.insert(nums[i]);
        }
        int ans=0;
        if(set.size()<3){
            return *max_element(set.begin(),set.end());
        }
        else if(set.size()==3){
            return *min_element(set.begin(),set.end());
        }
        else{
           int cnt=0;
           int k=set.size()-3;
            ans=0;
           for(auto i: set){
               if(cnt<=k){
                   ans = i;
                   cnt++;
               }
           }
           
        }
        return ans;
    }
};