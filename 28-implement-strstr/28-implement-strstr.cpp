class Solution {
public:
    int strStr(string haystack, string needle) {
        int stackLength = haystack.size();
        int needleLength = needle.size();
        for(int i=0; i<stackLength; i++){
            if(haystack[i]==needle[0]){
                int j=0;
                int k=i;
                while(j<needleLength and k<stackLength){
                    if(needle[j]!=haystack[k]){
                        break;
                    }
                    else{
                        j++; k++;
                    }
                }
                if(j==needleLength) return i;
            }
        }
        return -1;
    }
};