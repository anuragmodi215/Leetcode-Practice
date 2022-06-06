class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        unordered_map<string, int>mp;
        unordered_map<string,bool>visited;
        for(int i=0; i<n; i++){
            mp[wordList[i]]++;
        }
        if(mp.find(endWord)==mp.end()) return 0;
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        visited[beginWord]=1;
        int ans = INT_MAX;
        
        while(!q.empty()){
            string currWord = q.front().first;
            int cnt = q.front().second;
            if(currWord == endWord){
                ans = min(ans,cnt);
            }
            q.pop();
            for(int i=0; i<currWord.size(); i++){
                string newWord = currWord;
                for(char j = 'a'; j<='z'; j++){
                    newWord[i] = j;
                    if(mp.find(newWord)!=mp.end() and !visited[newWord]){
                        q.push({newWord,cnt+1});
                        visited[newWord]=1;
                    }
                }
            }
        }
        if(ans==INT_MAX) return 0;
        return ans;
    }
};