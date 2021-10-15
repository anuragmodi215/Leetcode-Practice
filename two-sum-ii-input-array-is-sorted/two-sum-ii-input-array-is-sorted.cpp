class Solution {
public:
    vector<int> twoSum(vector<int>& a, int target) {
        vector<int>v;
        int i=0,j=a.size()-1;
        while(i<j){
            if(a[i]+a[j]==target){
                v.push_back(i+1);
                v.push_back(j+1);
                return v;
            }
            else if(a[i]+a[j]<target)i++;
            else j--;
        }
        return v;
    }
};