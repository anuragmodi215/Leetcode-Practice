// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    static bool cmp(vector<int>&a, vector<int>&b){
        return a[1]<b[1];
    }
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        // Your code here
        vector<vector<int>>days(n,vector<int>(2,0));
        for(int i=0; i<n; i++){
            days[i][0] = start[i];
            days[i][1] = end[i];
        }
        sort(days.begin(),days.end(),cmp);
        int cnt=1;
        int takenday=days[0][1];
        for(int i=1; i<n; i++){
            if(takenday<days[i][0]){
                cnt++;
               takenday = days[i][1];
            }
            else if(days[i][0]>takenday){
                takenday = days[i][1];
                cnt++;
            }
        }
        return cnt;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends