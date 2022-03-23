class Solution {
public:
    bool divisorGame(int n) {
        //if our remainder is 1 that means Alice has no more moves
        return n%2==0;
    }
};