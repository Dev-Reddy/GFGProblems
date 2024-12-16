//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    
     long long memo[10000]; 
    long long mod = 1e9+7;
  public:
  
    Solution() {
        memset(memo, -1, sizeof(memo)); 
    }
    long long int topDown(int n) {
        // code here
        if(n<=1){
            return n;
        }
        
        if(memo[n]!=-1) return memo[n];
        
        
        memo[n] = (topDown(n-1) + topDown(n-2))%mod;
        return memo[n];
    }
    long long int bottomUp(int n) {
        // code here
        vector<long long int>dp(n+1);
        
        dp[0] = 0;
        dp[1] = 1;
        
        for(int i = 2;i<=n;i++){
            dp[i] = (dp[i-1] + dp[i-2])%mod;
        }
        
        return dp[n];
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    
cout << "~" << "\n";
}
}
// } Driver Code Ends