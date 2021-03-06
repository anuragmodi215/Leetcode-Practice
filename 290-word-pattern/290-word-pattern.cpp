class Solution {
public:
     vector<string> MakeMeString(string s, int s_size){
         vector<string>str;
         for(int i=0; i<s_size; i++){
            string k="";
            if(s[i]!=' '){
               while(s[i]!=' ' and i<s_size){
                k.push_back(s[i++]);
                } 
                str.push_back(k);
            }           
        }
         return str;
     }
    
    bool wordPattern(string pattern, string s) {
        int pat_size=pattern.size();
        int s_size=s.size();        
        vector<string>str=MakeMeString(s,s_size);
        
        int n=str.size();
        if(pat_size!=n) return false;
        
        unordered_map<char,string>mp;
        unordered_map<string,bool>bhulla;
                
        for(int i=0; i<n; i++){
            
            if(mp.find(pattern[i])==mp.end())
            {   
                if(bhulla.find(str[i])==bhulla.end()){
                     mp[pattern[i]]=str[i];
                     bhulla[str[i]]==1;
                }
                else if(bhulla.find(str[i])!=bhulla.end()) 
                    return false;              
            }
            
            else if(mp.find(pattern[i])!=mp.end())
            {
                if(mp[pattern[i]]!=str[i])
                return false;
            }
        }
        return true;
    }
};














