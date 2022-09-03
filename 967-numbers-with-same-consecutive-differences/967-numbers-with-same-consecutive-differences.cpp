class Solution {
public:
    vector<int>ans;
    void helper(int n, int k, string temp){
        if(temp.size()==n){
            ans.push_back(stoi(temp));
            return;
        }
        if(temp.size()==0){
            for(int i=1; i<=9; i++){
                temp.push_back(i+'0');
                helper(n,k,temp);
                temp.pop_back();
            }
        }
        else{
        
                int lastDigit = temp[temp.size()-1]-'0';
                if(lastDigit+k<=9){
                    int currDigit = lastDigit+k;
                    temp.push_back(currDigit+'0');
                    helper(n,k,temp);
                    temp.pop_back();
                }
                if(lastDigit-k>=0){
                    int currDigit = lastDigit-k;
                    if(temp[temp.size()-1]-'0'!=currDigit){
                        temp.push_back(currDigit+'0');
                        helper(n,k,temp);
                        temp.pop_back();
                    }
                    else return;
                }
            
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        helper(n,k,"");
        return ans;
    }
};