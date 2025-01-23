//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    
    int helper(const vector<int>& height, int i, vector<int>& memo){
        if(i==0) return 0;
        
        if(memo[i]!=-1) return memo[i];
        
        memo[i] = min(abs(height[i-1]-height[i])+helper(height, i-1, memo), 
        i>1? abs(height[i-2]-height[i])+helper(height, i-2, memo): INT_MAX);
        
        return memo[i];
    }
    
    
  public:
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        if(n==1) return 0;
        
        vector<int>memo(n,-1);
        
        return helper(height, n-1, memo);
    }
};

//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends