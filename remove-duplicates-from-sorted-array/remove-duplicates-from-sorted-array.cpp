class Solution {
public:
    int removeDuplicates(vector<int>& v) {
        if(v.size()==0) return 0;
        int i=1;
        int j=0;
        while(i<v.size()){
            if(v[i]==v[j]){
                i++;
            }
            else{
                v[++j] = v[i];
                i++;
            }
        }
        return j+1;
    }
};