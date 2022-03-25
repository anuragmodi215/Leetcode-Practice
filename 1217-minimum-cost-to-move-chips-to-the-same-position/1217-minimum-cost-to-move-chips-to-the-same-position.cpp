class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int odd_cnt=0;
        int even_cnt=0;
        for(auto i:position){
            if(i%2==0)even_cnt++;
            else odd_cnt++;
        }
        return min(even_cnt,odd_cnt);
    }
};