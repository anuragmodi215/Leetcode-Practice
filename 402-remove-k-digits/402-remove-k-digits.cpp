class Solution {
public:
    string removeKdigits(string nums, int k) {
        stack<char>st;
        int n=nums.size();
        
        for(int i=0; i<n; i++){
            if(st.empty()){
                st.push(nums[i]);
            }
            else{
                while(k>0 and !st.empty() and st.top()>nums[i]){
                    st.pop();
                    k--;
                    
                }
                 st.push(nums[i]);
            }
        }
        while(k>0){
            st.pop();
            k--;
        }
        //cout<<st.top();
        string ans="";
        while(!st.empty()){
            //if(st.top()!='0')
            ans.push_back(st.top());
            st.pop();
        }
        //cout<<ans;
        if(ans.size()==0) return "0";

        reverse(ans.begin(),ans.end());
        int ansLen=ans.size();
        int i;
        if(ans.size()>1){
            for(i=0; i<ansLen; i++){
            if(ans[i]=='0') continue;
            else break;
        }
        ans = ans.substr(i);
        }
        if(ans.size()==0) return "0";
        return ans;
    }
};