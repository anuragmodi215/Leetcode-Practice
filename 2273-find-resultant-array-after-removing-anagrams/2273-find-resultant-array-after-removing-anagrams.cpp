class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        string temp = words[0];
        vector<string>ans;
        ans.push_back(temp);
        sort(temp.begin(),temp.end());
        int n = words.size();
        for(int i=1; i<n; i++){
            string noob = words[i];
            sort(noob.begin(),noob.end());
            if(temp==noob)continue;
            else{
                ans.push_back(words[i]);
                temp = words[i];
                sort(temp.begin(),temp.end());
            }
        }
        return ans;
    }
};