class Solution {
public:
    void findCombination(int index, string input, string mapping[], vector<string>&ans,string output){
        if(index>=input.size()){
            ans.push_back(output);
            return;
        }
        int inputIndex = input[index]-'0';
        string s = mapping[inputIndex];
        for(int i=0; i<s.size(); i++){
            output.push_back(s[i]);
            findCombination(index+1,input,mapping,ans,output);
            output.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        string mapping[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string>ans;
        if(digits.size()==0) return ans;
        string output="";
        findCombination(0,digits,mapping,ans,output);
        return ans;
    }
};