// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    static bool cmp(Item a, Item b){
        double firstRatio = double(a.value/(double)a.weight);
        double secondRatio = double(b.value/(double)b.weight);
        return firstRatio>secondRatio;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr,arr+n,cmp);
        double profit = 0.0;
        int remain = 0;
        int currWeight = 0;
        int currPrice = 0;
        int weightTaken = 0;
        for(int i=0; i<n; i++){
           currWeight = arr[i].weight;
           currPrice = arr[i].value;
           if(currWeight+weightTaken<=W){
               weightTaken += currWeight;
               profit = profit+currPrice;
           }
           else{
               remain = W-weightTaken;
               profit = profit+((double)currPrice/(double)currWeight)*(double)remain;
               break;
           }
        }
        return profit;
    }
    
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends