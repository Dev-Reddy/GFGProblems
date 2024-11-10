//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  
  bool helper(vector<int>arr, int target, vector<vector<int>>dp, int ind){
      if(target==0) return true;
      
      if(ind==0) return target==arr[0];
      
      if(dp[ind][target]!=-1) return dp[ind][target];
      
      int notTake = helper(arr, target, dp, ind-1);
      
      int take = false;
      
      if(arr[ind]<=target) take = helper(arr, target-arr[ind], dp, ind-1);
      
      return dp[ind][target] = take | notTake;
  }
  
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<vector<bool>>dp(n, vector<bool>(sum+1, false));
        
        for(int i = 0;i<n;i++){
            dp[i][0] = true;
        }
        
        dp[0][arr[0]] = true;
        
        for(int ind = 1;ind<n;ind++){
            for(int target=1;target<=sum;target++){
                
                int notTake = dp[ind-1][target];
      
                int take = false;
                  
                if(arr[ind]<=target) take = dp[ind-1][target-arr[ind]];
                
                dp[ind][target] = take | notTake;
            }
        }
        
        return dp[n-1][sum];
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends