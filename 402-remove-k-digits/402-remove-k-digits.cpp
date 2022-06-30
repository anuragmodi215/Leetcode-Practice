class Solution {
public:
    string removeKdigits(string nums, int k) {
        int n = nums.size();
        bool containsZeroOnly=true;
        stack<char>st;
        for(int i=0; i<n; i++){
            while(k>0 and !st.empty() and st.top()>nums[i]){
                st.pop();
                k--;
            }
            st.push(nums[i]);
        }
        string ans = "";
        
        while(!st.empty() and k>0){
            st.pop();k--;
        }
        
        while(!st.empty()){
            ans.push_back(st.top());
            if(st.top()-'0'){
                containsZeroOnly = false;
            }
            st.pop();
        }
        if(ans.size()==0) return "0";
        if(containsZeroOnly) return "0";
        int i= ans.size()-1;
        while(i>0 and ans[i]=='0'){
            i--;
        }
        ans = ans.substr(0,i+1);
        reverse(ans.begin(),ans.end());
        return ans.substr(0,i+1);
    }
};