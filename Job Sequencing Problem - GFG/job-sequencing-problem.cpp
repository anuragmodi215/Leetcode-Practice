// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool cmp(Job a, Job b){
        return a.profit>b.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr,arr+n,cmp);
        int totalProfit=0;
        int jobs=0;
        int id[110]={0};
        // for(auto i:id){
        //     cout<<i<<" ";
        // }
        //cout<<endl;
        for(int i=0; i<n; i++){
            //cout<<arr[i].dead<<" ";
            if(id[arr[i].dead]==0){
                jobs++;
                id[arr[i].dead] = arr[i].profit;
                totalProfit+=arr[i].profit;
                //cout<<1;
            }
            else{
                int j = arr[i].dead;
                while(j>=1 and id[j]!=0){
                    j--;
                }
                if(j>=1){
                    id[j] = arr[i].profit;
                    jobs++;
                    totalProfit+=arr[i].profit;
                }
            }
        }
        return {jobs,totalProfit};
    } 
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends