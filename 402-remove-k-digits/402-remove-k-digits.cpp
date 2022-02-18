class Solution {
public:
    string removeKdigits(string nums, int k) {
        int n=nums.size();
        stack<char>st;
        for(int i=0; i<n; i++){
            while(!st.empty() and k>0 and st.top()>nums[i]){
                st.pop();
                k--;
            }
            st.push(nums[i]);
        }
        
        while(k>0){
            st.pop();
            k--;
        }
        bool containsOnlyZeros=true;;
        string ans="";
        while(!st.empty()){
            ans=st.top()+ans;
            if(st.top()!='0'){
                containsOnlyZeros=false;
            }
            st.pop();
        }
        if(containsOnlyZeros) return "0";
        //reverse(ans.begin(),ans.end());
        int i;
        int ansLen=ans.size();
        for(i=0; i<ansLen; i++){
            if(ans[i]=='0') continue;
            else break;
        }
        ans=ans.substr(i);
        return ans;
    }
};








