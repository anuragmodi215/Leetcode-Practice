class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n=pushed.size();
        stack<int>stack;
        int index=0;
        for(int i=0; i<n; i++){
            if(stack.empty()){
                stack.push(pushed[i]);
            }
            else{
                while(!stack.empty() and stack.top()==popped[index]){
                    stack.pop();
                    index++;
                }
                stack.push(pushed[i]);
            }
        }
        
        while(index<n){
            if(stack.top()==popped[index]){
                stack.pop(); index++;
            }
            else break;
        }
        if(stack.empty()) return true;
        else return false;
    }
};