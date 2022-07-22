class Solution {
public:
    int minSwaps(string s) {
        stack<char>st;
        int cnt=0;
        for(auto i:s){
            if(i=='['){
                st.push(i);
            }
            else{
                if(!st.empty() and st.top()=='['){
                    st.pop();
                }
                else{
                    cnt++;   
                }
            }
        }
        cout<<cnt;
        return (cnt+1)/2;
    }
};