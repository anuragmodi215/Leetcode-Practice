class Solution {
public:
    string multiply(string a, string b) {
        if(a[0]=='0' or b[0]=='0') return "0";
        int n = a.size();
        int m = b.size();
        vector<int>v(n+m);
        string ans ="";
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                v[i+j+1]+=(a[i]-'0')*(b[j]-'0');
                v[i+j]+=(v[i+j+1]/10);
                v[i+j+1] = v[i+j+1]%10;
            }
        }
        int i=0;
        while(i<v.size() and v[i]==0)i++;
       
        for(int j=i; j<v.size(); j++){
            ans.push_back(v[j]+'0');
        }
        return ans;
    }
};