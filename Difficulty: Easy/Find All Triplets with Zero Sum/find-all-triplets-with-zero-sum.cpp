//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<vector<int>> findTriplets(vector<int> &arr) {
        // Code here
        vector<vector<int>> ans; // To store the result triplets
        unordered_map<int, vector<int>> mp; // Hashmap to store each element and its indices

        // Step 1: Populate the hashmap with each element and its corresponding index
        for(int i = 0; i < arr.size(); ++i) {
            mp[arr[i]].push_back(i);
        }

        // Step 2: Iterate through each pair (i, j) using two nested loops
        for(int i = 0; i < arr.size(); ++i) {
            for(int j = i + 1; j < arr.size(); ++j) {
                int tt = arr[i] + arr[j];  // Calculate the sum of the current pair
                int req = -tt;             // Calculate the required third element to make the sum zero

                // Check if the required element exists in the hashmap
                if(mp.find(req) != mp.end()) {
                    for(int x : mp[req]) { // Iterate over all indices of the required element
                        // Ensure that the indices satisfy i < j < k
                        if(x != i && x != j && i < j && j < x) {
                            vector<int> temp = {i, j, x}; // Form the triplet
                            ans.push_back(temp);          // Add the triplet to the result
                        }
                    }
                }
            }
        }

        return ans; // Return all the valid triplets
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
        Solution ob;

        vector<vector<int>> res = ob.findTriplets(arr);
        sort(res.begin(), res.end());
        if (res.size() == 0) {
            cout << "[]\n";
        }
        for (int i = 0; i < res.size(); i++) {
            for (int j = 0; j < res[i].size(); j++) {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends