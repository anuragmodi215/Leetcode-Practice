class Solution {
public:
    bool canConstruct(string a, string b) {
     int n1 = a.size();
     int n2 = b.size();
     if(n1>n2) return false;
        
        vector<int>freq1(26,0);
        vector<int>freq2(26,0);
        for(int i=0; i<n1; i++){
            freq1[a[i]-'a']++;
        }
        for(int i=0; i<n2; i++){
            freq2[b[i]-'a']++;
        }
        
        for(int i=0; i<n1; i++){
            if(freq2[a[i]-'a']<freq1[a[i]-'a']){
                return false;
            }
        }
        return true;
    }
};