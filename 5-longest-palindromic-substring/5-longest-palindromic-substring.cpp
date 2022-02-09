class Solution {
public:
    int low,length;
    void helper(string &s, int left, int right, int n){
        string str;
        //int len=0;
        while(left>=0 and right<n){
            if(s[left]==s[right]){
                if(right-left+1>length){
                    low=left;
                    length=right-left+1;
                    //len=length;
                }
                left--; right++;
            }
            else break;
        }
        cout<<length<<" "<<low<<endl;
        //cout<<str<<endl;
        //return str;
        return;
    }
    string longestPalindrome(string s) {
        int n=s.size();
        low=0,length=0;
        
        for(int i=0; i<n; i++){
         helper(s,i,i,n);
         helper(s,i,i+1,n);
        }
        cout<<length;
        string ans=s.substr(low,length);
        return ans;
    }
};