class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end(), greater<int>());
        //for(auto i:piles) cout<<i<<" ";
        int myPiles = 0;
        int n = piles.size();
        int i=0, j=n-1;
        while(i<j){
            if(i+1<j){
                myPiles+=piles[i+1];
            }
            i=i+2;
            j--;
        }
        return myPiles;
    }
};