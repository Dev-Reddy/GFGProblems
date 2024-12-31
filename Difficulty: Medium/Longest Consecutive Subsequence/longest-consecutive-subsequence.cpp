//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        // Your code here
         // Using a set to store unique elements.
        set<int> st(arr.begin(), arr.end());

        int ans = 0; // Variable to store the maximum length.

        // Iterate through each element of the array.
        for (int i = 0; i < arr.size(); ++i) {
            int cnt = 0;

            // Check if the current element is a starting point of a sequence.
            if (st.find(arr[i] - 1) == st.end()) {
                // Increment counter for each consecutive element found.
                while (st.find(arr[i] + cnt) != st.end()) {
                    ++cnt;
                }

                // Update the maximum length.
                ans = max(ans, cnt);
            }
        }

        return ans; // Return the longest length.
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.longestConsecutive(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends