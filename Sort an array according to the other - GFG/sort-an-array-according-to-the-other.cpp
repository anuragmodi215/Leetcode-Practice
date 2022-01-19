// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std;


 // } Driver Code Ends
//User function template in C++


class Solution{
    public:
    // A1[] : the input array-1
    // N : size of the array A1[]
    // A2[] : the input array-2
    // M : size of the array A2[]
    
    //Function to sort an array according to the other array.
    vector<int> sortA1ByA2(vector<int> a1, int n, vector<int> a2, int m) 
    {
        //Your code here
        map<int,int>mp;
        for(int i=0; i<m; i++){
            mp[i]=a2[i];
        }
       map<int,int>freq;
        
        for(int i=0; i<n; i++){
            freq[a1[i]]++;
        }
        vector<int>ans;
        
        for(auto i:mp){
            int element=i.second;
            if(freq.find(element)!=freq.end()){
                int times=freq[element];
                for(int j=0; j<times; j++){
                    ans.push_back(element);
                    freq[element]--;
                    if(freq[element]==0)freq.erase(element);
                }
            }
        }
        for(auto i: freq){
            int times=i.second;
            int el=i.first;
            for(int i=0; i<times; i++){
                ans.push_back(el);
            }
        }
        return ans;
    } 
};

// { Driver Code Starts.

int main(int argc, char *argv[]) 
{ 
	
	int t;
	
	cin >> t;
	
	while(t--){
	    
	    int n, m;
	    cin >> n >> m;
	    
	    vector<int> a1(n);
	    vector<int> a2(m);
	    
	    for(int i = 0;i<n;i++){
	        cin >> a1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> a2[i];
	    }
	    
	    Solution ob;
	    a1 = ob.sortA1ByA2(a1, n, a2, m); 
	
	   
	    for (int i = 0; i < n; i++) 
		    cout<<a1[i]<<" ";
		
	    cout << endl;
	    
	    
	}
	return 0; 
} 
  // } Driver Code Ends