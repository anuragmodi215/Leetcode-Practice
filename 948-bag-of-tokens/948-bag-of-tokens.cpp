class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int i=0,j=tokens.size()-1;
        int maxScore = 0;
        int score = 0;
        while(i<=j){
            if(tokens[i]<=power){
                power-=tokens[i];
                score++;
                maxScore = max(maxScore,score);
                i++;
            }
            else if(score){
                power+=tokens[j];
                score--;
                maxScore = max(maxScore,score);
                j--;
            }
            else break;
        }
        return maxScore;
    }
};