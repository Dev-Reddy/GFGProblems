//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxLen(vector<int> &arr) {
         int n = arr.size();
        unordered_map<int, int> prefixSumIndex; // Stores first occurrence of each sum
        int sum = 0;  // To track the cumulative sum
        int maxLength = 0; // To store the result

        for (int i = 0; i < n; ++i) {
            // Replace 0 with -1 for balance checking
            sum += (arr[i] == 0 ? -1 : 1);

            // If the cumulative sum is zero, the subarray from the start is balanced
            if (sum == 0) {
                maxLength = max(maxLength, i + 1);
            }

            // If sum already exists in the map, a balanced subarray is found
            if (prefixSumIndex.find(sum) != prefixSumIndex.end()) {
                maxLength = max(maxLength, i - prefixSumIndex[sum]);
            } else {
                // Store the first occurrence of the sum
                prefixSumIndex[sum] = i;
            }
        }

        return maxLength;
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore(); // To ignore the newline character after reading T

    while (T--) {
        string line;
        getline(cin, line); // Read the whole line for the array

        // Convert the line into an array of integers
        stringstream ss(line);
        vector<int> a;
        int num;
        while (ss >> num) {
            a.push_back(num);
        }

        // Create the solution object
        Solution obj;

        // Call the maxLen function and print the result
        cout << obj.maxLen(a) << endl;
    }

    return 0;
}
// } Driver Code Ends