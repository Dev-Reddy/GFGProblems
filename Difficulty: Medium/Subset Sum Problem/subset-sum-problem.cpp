//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
    
    bool helper(vector<int>& arr, int target, int ind, 
    vector<vector<int>> &memo){
        
        if(target==0) return true;
        
        if(ind==0) return target==arr[0];
        
        if(memo[ind][target]!=-1) return memo[ind][target];
        
        // take 
        
        bool take = false;
        
        if(arr[ind]<=target){
            take = helper(arr, target-arr[ind], ind-1, memo);
        }
        
        // not take
        bool notTake = helper(arr, target, ind-1, memo);
        
        memo[ind][target] =  take || notTake;
        
        return memo[ind][target];
    }
    
    
  public:
    bool isSubsetSum(vector<int>& arr, int target) {
        // code here
        
        vector<vector<int>> memo(arr.size(), vector<int>(target+1, -1));
        
        return helper(arr, target, arr.size()-1, memo);
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