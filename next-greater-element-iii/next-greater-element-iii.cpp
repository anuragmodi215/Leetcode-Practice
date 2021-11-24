class Solution {
public:
    int nextGreaterElement(int n) {
        string s=to_string(n);
        int len = s.size();
        int first=len-1;
        for(int i=len-1; i>0; i--){
            if(s[i]>s[i-1]){
                first=i-1;
                break;
            } 
            cout<<first<<" ";
        }
    //cout<<first<<endl;
        int second=0;
        for(int i=first; i<len; i++){
            if(s[i]>s[first]) second = i;
        }
        swap(s[first],s[second]);
        reverse(s.begin()+first+1,s.end());
        cout<<s<<endl;
        long long int ans=stol(s);
        if(ans>n and ans<=INT_MAX) return ans;
        return -1;
        //return n;
    }
};