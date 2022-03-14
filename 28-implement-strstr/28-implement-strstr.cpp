class Solution {
public:
    int strStr(string haystack, string needle) {
        int len = needle.size();
        //string temp;
        int n = haystack.size();
        if(n==0 and len==0) return 0;
        for(int i=0; i<n; i++){
            if(i+len<=n){
                //cout<<i+len<<endl;
                string temp = haystack.substr(i,len);
                //cout<<temp<<endl;
                if(temp==needle) return i;
            }
        }
        return -1;
    }
};