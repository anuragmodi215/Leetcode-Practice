class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int strt=0,n=letters.size(),end=n-1; char x;
        if(letters.back()<=target) return letters.front();
        while(strt<=end){
            int mid=strt+(end-strt)/2;
            if(letters[mid]>target){
                x=letters[mid];
                end=mid-1;
            }
            else strt=mid+1;
        }
        return x;
    }
};