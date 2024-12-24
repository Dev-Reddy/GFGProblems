//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    
    bool isPossible(vector<vector<int>> &adj, vector<int>&col, int ind, int c){
        for(int i = 0;i<adj[ind].size();i++){
            int neighbor = adj[ind][i];
            if(col[neighbor]==c) return false;
        }
        return true;
    }
    
    bool helper(int ind, vector<vector<int>> &adj, vector<int>&col, int v, int m){
        
        if(ind==v) return true;
        
        for(int c =1; c<=m;c++){
            if(isPossible(adj, col, ind, c)){
                col[ind] = c;
                if (helper(ind+1, adj, col, v, m)) return true;
                col[ind] = 0;
            }
        }
        return false;
    }
    
    
  public:
    bool graphColoring(int v, vector<pair<int, int>>& edges, int m) {
        // code here
        vector<vector<int>> adj(v);
        
        for(auto i: edges){
            adj[i.first].push_back(i.second);
            adj[i.second].push_back(i.first);
        }
        
        vector<int>col(v,0);
        
        return helper(0, adj, col, v, m);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m;
        cin >> n;
        cin.ignore(); // Ignore newline after reading n
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number); // Populate the array with edge values
        }
        cin >> m;
        cin.ignore(); // Ignore newline after reading m

        int edges_count = arr.size();
        vector<pair<int, int>> edges(edges_count /
                                     2); // Correct size of the edges vector

        for (int i = 0; i < edges_count; i += 2) {
            int l1 = arr[i];
            int l2 = arr[i + 1];
            edges[i / 2] = {l1, l2}; // Properly assign the pair
        }

        Solution ob;
        cout << (ob.graphColoring(n, edges, m) ? "true" : "false")
             << "\n~\n"; // Call the graph coloring function
    }
    return 0;
}

// } Driver Code Ends