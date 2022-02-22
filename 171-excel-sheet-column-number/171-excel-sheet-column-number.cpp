class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans=0;
        for(auto c:columnTitle){
            int temp = c -'A'+1;
            ans = ans*26+temp;
        }
        return ans;
    }
};