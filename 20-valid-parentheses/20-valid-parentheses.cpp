class Solution {
public:
    bool isValid(string s) {
        stack<char>stack;
        int n=s.size();
        if(n%2==1) return false;
        for(auto &i:s)
        {
            if(i=='(' or i=='{' or i=='[')
            {
                stack.push(i);
            }
            else
            {
                if(!stack.empty()){
                    if(i==')' and stack.top()=='(')
                    {
                        stack.pop();
                    }
                    else if(i=='}' and stack.top()=='{')
                    {
                        stack.pop();
                    }
                    else if(i==']' and stack.top()=='[')
                    {
                        stack.pop();
                    }
                    else return false;
                }
                else return false;
            }
        }
        if(stack.empty()) return true;
        else return false;
    }
};