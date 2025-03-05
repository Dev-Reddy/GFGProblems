//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int longestStringChain(vector<string>& words) {
        // Code here
        int n = words.size();
        // Group words by their lengths using a vector of unordered sets
        vector<unordered_set<string>> mp(11);
        // DP map to store the length of the longest word chain ending at each word
        map<string, int> dp;
        
        // Initialize DP table with single-letter words
        for(string &s : words){
            if(s.length() == 1) dp[s] = 1;
            mp[s.length()].insert(s);
        }
        
        int ans = 1; // Initialize the answer with the minimum possible chain length
        
        // Iterate through word lengths from 2 to 10
        for(int i = 2; i <= 10; ++i){
            for(auto &s : mp[i]){
                dp[s] = 1; // Initialize the current word's chain length to 1
                // Generate all possible predecessors by removing one character at a time
                for(int j = 0; j < s.length(); ++j){
                    string temp = s.substr(0, j) + s.substr(j + 1);
                    // Check if the predecessor exists in the previous length group
                    if(mp[i - 1].count(temp)){
                        // Update the DP table with the maximum chain length
                        dp[s] = max(dp[s], 1 + dp[temp]);
                    }
                }
                // Update the answer with the maximum chain length found
                ans = max(ans, dp[s]);
            }
        }
        
        return ans; // Return the length of the longest word chain
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> words;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            words.push_back(number);
        }
        Solution obj;
        cout << obj.longestStringChain(words) << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends