class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(auto i:nums){
            mp[i]++;
        }
        long long int length,maxi;
        if(n>0) length=1;
        else length=0;
        maxi=length;
        for(auto i:mp){
            int number=i.first;
            if(mp.find(number-1)!=mp.end()){
                continue;
            }
            else{
                while(mp.find(number+1)!=mp.end()){
                number+=1;
                length+=1;
            }
            }
            
            maxi=max(length,maxi);
            length=1;
        }
        return maxi;
    }
};