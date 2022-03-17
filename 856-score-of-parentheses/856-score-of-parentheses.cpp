class Solution {
public:
    int scoreOfParentheses(string s) {
        //stack<int>stack;
        int n=s.size();
        int score=0;
        int cnt=0;
        for(int i=0; i<n; i++){
            if(s[i]=='('){
                cnt++;
            }
            else{
                cnt--;
                if(s[i-1]=='('){
                    score=score+pow(2,cnt);
                }
            }
        }
        return score;
    }
};