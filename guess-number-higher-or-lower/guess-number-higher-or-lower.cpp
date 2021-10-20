/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int strt=0,end=n;
        while(strt<end){
            int mid=strt+(end-strt)/2;
            if(guess(mid)==0) return mid;
            else if(guess(mid)==-1)end=mid-1;
            else strt=mid+1;
        }
        return end;
    }
};