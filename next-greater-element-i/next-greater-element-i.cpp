class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>mp;
        int n=nums2.size();
        stack<int>st;
        vector<int>ans;
        for(int i=n-1; i>=0; i--){
            if(st.empty())
            {
                mp[nums2[i]]=-1;
            }
            else if(st.top()>nums2[i])
            {
                mp[nums2[i]]=st.top();
            }
            else{                
                while(!st.empty())
                {
                    if(st.top()>nums2[i]){
                        mp[nums2[i]]=st.top();
                        break;
                    }
                    else st.pop();
                }
                if(st.empty()) mp[nums2[i]]=-1;
            }
            st.push(nums2[i]);
        }
        n=nums1.size();
        for(int i=0; i<n; i++){
            ans.push_back(mp[nums1[i]]);
        }
        return ans;
    }
};












