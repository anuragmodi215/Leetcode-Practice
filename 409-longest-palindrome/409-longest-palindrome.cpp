class Solution {
public:
    int longestPalindrome(string s) {
        int n=s.size();
        unordered_map<char,int>mp;
        for(int i=0; i<n; i++){
            mp[s[i]]++;
        }
        bool ok=0;
        int even_cnt=0;
        int odd_cnt=0;
        for(auto i:mp){
            if(i.second%2==0){
                even_cnt+=i.second;
            }
            else{
                ok=1;
                odd_cnt=odd_cnt+(i.second-1);
            }
        }
        cout<<odd_cnt;
        if(ok)
        return even_cnt+odd_cnt+1;
        else return even_cnt;
    }
};