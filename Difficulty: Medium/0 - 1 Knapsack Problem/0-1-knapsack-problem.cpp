//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return max value that can be put in knapsack of capacity.
    int knapSack(int capacity, vector<int> &val, vector<int> &wt) {
        // code here
        vector<int>prev(capacity+1, 0), curr(capacity+1, 0);
        
        for(int i = wt[0];i<=capacity;i++){
            prev[i] = val[0];
        }
        
        for(int i = 1;i<val.size();i++){
            for(int w = 0;w<=capacity;w++){
                int notTake = prev[w];
                
                int take = INT_MIN;
                
                if(wt[i]<=w){
                    take = val[i] + prev[w-wt[i]];
                }
                
                curr[w] = max(take, notTake);
            }
            prev = curr;
        }
        
        return prev[capacity];
    }
};

//{ Driver Code Starts.

int main() {
    // Taking total test cases
    int testCases;
    cin >> testCases;
    cin.ignore();
    while (testCases--) {
        // Reading number of items and capacity
        int numberOfItems, capacity;
        vector<int> weights, values;
        string input;
        int number;

        // Read capacity and number of items
        getline(cin, input);
        stringstream ss(input);
        ss >> capacity;      // The first number is the capacity
        ss >> numberOfItems; // The second number is the number of items

        // Read values
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            values.push_back(number);
        }

        // Read weights
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            weights.push_back(number);
        }

        Solution solution;
        cout << solution.knapSack(capacity, values, weights) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends