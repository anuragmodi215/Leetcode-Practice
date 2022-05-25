class Solution {
public:
    bool find(string&word, string&b){
        int len = word.size()-b.size()+1;
        int b_size = b.size();
        int ind = 0;
        for(int i=0; i<word.size(); i++){
            if(word[i]!=b[ind]) continue;
            else{
                int j=0;
                int k=i;
                while(j<b.size() and k<word.size()){
                    if(word[k]!=b[j]){
                        //cout<<j;
                        break;
                    }
                    else{
                        k++;j++;
                    }
                    // cout<<i
                }
                
                if(j==b.size()) return true;
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