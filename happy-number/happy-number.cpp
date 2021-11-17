class Solution {
public:
    bool isHappy(int n) {
        long long int sum=0,x=n;
        set<long long int>set;
        while(1){
            if(x==1) return true;
            while(x>0){
                int mod = x%10;
                sum = sum+pow(mod,2);
                x=x/10;
            }
            
            if(set.find(sum)!=set.end()) return false;
                
            set.insert(sum);
                
            x=sum;
            sum=0;
            cout<<x<<" ";
        }
        return false;
    }
};