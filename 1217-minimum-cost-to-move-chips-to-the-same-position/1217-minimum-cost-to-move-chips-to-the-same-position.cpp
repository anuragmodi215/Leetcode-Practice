class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
//         since cost of moving a coin +2 or -2 is Zero therfore we will
//         either move even coins or odd coins to either even position or odd position
//
//          take all coins to 1 3 5 7 9 or all coins to 0 2 4 6 8
        
//         either take all coins to odd position or all coins to even position
//         then the cost of +2 move or -2 move is 0
        
        int even=0,odd=0;
        for(auto i:position){
            if(i%2==0){
                even++;
            }
            else{
                odd++;
            }
        }
        return min(odd,even);
    }
};