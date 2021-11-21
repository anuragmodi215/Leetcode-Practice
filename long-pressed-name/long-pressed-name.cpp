class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i=0,j=0;
        int name_size=name.size();
        int typed_size=typed.size();
        while(j<typed_size){
            if(name[i]==typed[j])
            {
                i++; j++;
            }
            else if(i>0 and name[i-1]==typed[j])
            {
                j++;
            }
            else return false;
        }
        if(i==name_size)
        return true;
        return false;
    }
};