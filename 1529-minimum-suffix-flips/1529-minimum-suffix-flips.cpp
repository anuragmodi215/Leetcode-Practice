class Solution {
public:
    int minFlips(string target) {
        int n = target.size();
        string s(n,'0');
        //cout<<s;
        int moves=0;
        char currChar = s[0];
        for(int i=0; i<n; i++){
            if(currChar==target[i])continue;
            
            currChar = target[i];
            moves++;
        }
        return moves;
    }
};