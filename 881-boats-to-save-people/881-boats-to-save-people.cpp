class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n=people.size();
        sort(people.begin(),people.end());
        
        int cnt=0,i=0,j=n-1;
        
        while(i<=j){
            cnt++;
            if(people[i]+people[j]<=limit){
                i++;j--;
            }
            else j--;
        }
        return cnt;
    }
};