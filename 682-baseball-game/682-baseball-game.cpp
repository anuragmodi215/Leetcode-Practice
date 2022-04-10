class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int>stack;
        
        for(auto i:ops){
            
            if(i=="+"){
                int a = stack.top(); stack.pop();
                int b = stack.top(); stack.pop();
                int res = a+b;
                stack.push(b);
                stack.push(a);
                stack.push(res);
            }
            
            else if(i=="C" or i=="D"){
                //cout<<stack.top();
                if(i=="C") stack.pop();
                
                else if(i=="D"){
                    int a = stack.top();
                    int res = 2*a;
                    stack.push(res);
                }
            }
            
            else{
                int x = stoi(i);
                //cout<<x;
                stack.push(x);
            }
        }
        long long int ans=0;
        while(!stack.empty()){
            //cout<<stack.top();
            ans+=stack.top();
            stack.pop();
        }
        return ans;
    }
};