class Solution {
public:
    string multiply(string num, string number) {
        int rem=0;
        string ans="";
        int n=num.size(),m=number.size();
        vector<int>v(n+m);
        if(num=="0" or number=="0") return "0";
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                v[i+j+1]+=(num[i]-'0')*(number[j]-'0');
                v[i+j]+=v[i+j+1]/10;
                v[i+j+1]%=10;
            }
        }
        
        int i=0;
        //string ans="";
        while(i<n+m and v[i]==0) i++;
        
        for(int j=i; j<n+m; j++){
            ans.push_back(v[j]+'0');
        }
        return ans;
    }
};