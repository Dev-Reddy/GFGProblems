//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    
    long long int mod = 1000000007; 
    
    long long int helper(vector<long long int> &memo, int n){
        if(n<=1) return n;
        
        if(memo[n]!= -1) return memo[n];
        
        memo[n] = (helper(memo, n-1) + helper(memo, n-2))%mod;
        
        return memo[n];
        
    }
    
    
  public:
    long long int topDown(int n) {
        // code here
        vector<long long int>memo(n+1, -1);
        
        return helper(memo, n);
        
    }
    long long int bottomUp(int n) {
        // code here
        if(n<=1) return n;
        
        long long int a = 0;
        long long int b = 1;
        
        for(int i = 2;i<=n;i++){
            long long int c = (a+b)%mod;
            a = b;
            b = c;
        }
        
        return b;
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