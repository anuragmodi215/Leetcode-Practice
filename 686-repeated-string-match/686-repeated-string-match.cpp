class Solution {
public:
    bool find(string&word, string&b){
        int len = word.size()-b.size()+1;
        int b_size = b.size();
        for(int i=0; i<len; i++){
            if(word.substr(i,b_size)==b){
                return true;
            }
        }
        return false;
    }
    int repeatedStringMatch(string a, string b) {
        string word = "";
        int n = b.size();
        int cnt=0;
        while(word.size()<n){
            word+=a;
            cnt++;
        }
         //cout<<word;
        bool successfullSearch = find(word,b);
        if(!successfullSearch){
            cnt++;
            word+=a;
        }
        //cout<<word;
        successfullSearch = find(word,b);
        if(!successfullSearch){
            return -1;
        }
        return cnt;
    }
};