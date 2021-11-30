class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int win=k+1;
        int n=nums.size();
        int i=0,j=0;
        set<int>set;
        while(j<n){
            if(j-i+1<win){
                if(set.find(nums[j])==set.end()) set.insert(nums[j]);
                else return true;
                j++;
            }
            else{
                if(set.find(nums[j])==set.end()) set.insert(nums[j]);
                else return true;
                auto it = set.find(nums[i]);
                set.erase(it);
                i++;j++;
            }
        }
        return false;
    }
};