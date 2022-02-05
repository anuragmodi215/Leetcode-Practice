class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int n=strs.size();
        string a=strs[0];
        string b=strs[n-1];
        
        int n1=a.size();
        int n2=b.size();
        int i=0,j=0;
        string ans="";
        while(i<n1 and j<n2){
            if(a[i]==b[j]){
                ans.push_back(a[i]);
                i++;j++;
            }
            else break;
        }
        return ans;
    }
};