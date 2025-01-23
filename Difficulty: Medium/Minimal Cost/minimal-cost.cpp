//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    
    int helper(const vector<int>& height, int i, int k, vector<int>& memo){
        if(i==0) return 0;
        
        if(memo[i]!=-1) return memo[i];
        
        memo[i] = INT_MAX;
        
        for(int j = 1; j<=k;j++){
            
            memo[i] = min(memo[i], i-j>=0 ? abs(height[i-j]-height[i])
            +helper(height, i-j, k, memo):INT_MAX);
        }
        
        
        return memo[i];
    }
  public:
    int minimizeCost(int k, vector<int>& arr) {
        // Code here
            // Code here
        int n = arr.size();
        if(n==1) return 0;
        
        vector<int>memo(n,-1);
        
        return helper(arr, n-1, k, memo);
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(k, arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends