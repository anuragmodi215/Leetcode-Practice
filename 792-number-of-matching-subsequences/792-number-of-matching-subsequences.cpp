class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<string,int>mp;
        for(int i=0; i<words.size(); i++){
            mp[words[i]]++;
        }
        int cnt=0;
        for(auto k:mp){
            string newWord = k.first;
            int n = newWord.size();
            int i=0,j=0;
            while(i<n and j<s.size()){
                if(newWord[i]==s[j]){
                    i++;j++;
                }
                else{
                    j++;
                }
            }
            if(i==n){
                cnt+=k.second;
            }
        }
        return cnt;
    }
};