// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find the minimum indexed character.
    int minIndexChar(string str, string patt)
    {
        // Your code here
        unordered_map<char,int>mp;
        int n=str.size();
        for(int i=0; i<n; i++){
            if(mp.find(str[i])==mp.end())
            mp[str[i]]=i;
        }
        
        n=patt.size();
        int ind=INT_MAX;
        int mini=INT_MAX;
        for(int i=0; i<n; i++){
            if(mp.find(patt[i])!=mp.end()){
                ind=mp[patt[i]];
                mini=min(ind,mini);
            }
        }
        if(mini==INT_MAX) return -1;
        else return mini;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
    cin>>t;
    while(t--)
    {
        string str;
        string patt;
        cin>>str;
        cin>>patt;
        Solution obj;
        cout<<obj.minIndexChar(str, patt)<<endl;
    }
	return 0;
}
  // } Driver Code Ends