class Solution {
public:
    string helper(int n, string input){
        //cout<<input<<endl;
        if(n<=1) return input;
        unordered_map<char,int>mp;
        for(int i=0; i<input.size(); i++){
            mp[input[i]]++;
        }
        string output = "";
        int cnt=1;
        for(int i=0; i<input.size(); i++){
            if(i+1<input.size() and input[i]==input[i+1]){
                cnt++;
            }
            else{
                output.push_back(cnt+'0');
                output.push_back(input[i]);
                cnt=1;
            }
        }
        // output.push_back(cnt+'0');
        // output.push_back(input[i-1]);
        return helper(n-1,output);
    }
    string countAndSay(int n) {
        return helper(n,"1");
    }
};