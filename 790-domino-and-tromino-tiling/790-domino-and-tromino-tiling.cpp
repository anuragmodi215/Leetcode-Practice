class Solution {
public:
    int numTilings(int n) {
        if(n<3) return n;
        vector<long long int>Domino(n+1);
        vector<long long int>Tromino(n+1);
        Domino[0]=0;
        Domino[1]=1;
        Domino[2]=2;
        Tromino[0]=0;
        Tromino[1]=1;
        Tromino[2]=2;
        int mod = pow(10,9)+7;
        for(int i=3; i<n+1; i++){
            Domino[i]=(Domino[i-1]+Domino[i-2]+(2*(Tromino[i-2]))%mod)%mod;
            Tromino[i]=(Tromino[i-1]+Domino[i-1])%mod;
        }
        //cout<<Domino[n]<<" "<<Tromino[n]<<endl;
        return Domino[n];
    }
};