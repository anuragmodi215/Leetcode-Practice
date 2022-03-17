class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>stack;
        int n=s.size();
        int score=0;
        for(int i=0; i<n; i++){
            if(s[i]=='('){
                stack.push(score);
                score=0;
            }
            else{
                score=stack.top()+max(score*2,1);
                stack.pop();
            }
        }
        return score;
    }
};