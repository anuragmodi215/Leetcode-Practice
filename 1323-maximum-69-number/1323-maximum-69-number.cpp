class Solution {
public:
    int maximum69Number (int nums) {
        string s = to_string(nums);
        for(int i=0; i<s.size(); i++){
            if(s[i]=='6'){
                s[i]='9';
                break;
            }
        }
        return stoi(s);
    }
};