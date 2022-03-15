class Solution {
public:
    string minRemoveToMakeValid(string s) {
     int n=s.size();
        stack<int>stack;
        int cnt=0;
        for(int i=0; i<n; i++){
            if(s[i]=='('){
                stack.push(i);
                cnt++;
            }
            else if(s[i]==')'){
                if(cnt>0){
                    stack.pop();
                    cnt--;
                }
                else{
                    stack.push(i);
                }
            }
        }
        
        while(!stack.empty()){
            s.erase(stack.top(),1);
            stack.pop();
        }
        return s;
    }
};