// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:    
       vector <int> commonElements (int a[], int b[], int c[], int n1, int n2, int n3)
        {
            //code here.
            int i=0,j=0,k=0;
            vector<int>ans;
            while(i<n1 and j<n2 and k<n3){
                if(a[i]==b[j] and a[i]==c[k]){
                    if(ans.size()==0){
                        ans.push_back(a[i]);
                    }
                    else if(ans.back()!=a[i]){
                        ans.push_back(a[i]);
                    }
                    i++;j++;k++;
                }
                else if(a[i]>b[j] and a[i]>c[k]){
                    j++;k++;
                }
                else if(b[j]>a[i] and b[j]>c[k]){
                    i++;k++;
                }
                else if(c[k]>a[i] and c[k]>b[j]){
                    i++;j++;
                }
                else if(a[i]==b[j]){
                    k++;
                }
                else if(b[j]==c[k]){
                    i++;
                }
                else if(a[i]==c[k]){
                    j++;
                }
            }
            return ans;
        }
};

// { Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; 
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];
        
        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];
        
        Solution ob;
        
        vector <int> res = ob.commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0) 
            cout << -1;
        for (int i = 0; i < res.size (); i++) 
            cout << res[i] << " "; 
        cout << endl;
    }
}  // } Driver Code Ends