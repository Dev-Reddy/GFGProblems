//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    bool matSearch(vector<vector<int>> &mat, int x) {
        // your code here
         int n = mat.size(), m = mat[0].size();
        
        // Start from the top-right corner
        int i = 0, j = m - 1; 
        
        // Traverse the matrix within bounds
        while (i < n && j >= 0) {
            // If the current element matches x, return true
            if (mat[i][j] == x) 
                return true;
            
            // If the current element is smaller than x,
            // move to the next row as elements in the current row are all smaller
            if (mat[i][j] < x) 
                ++i;
            // If the current element is greater than x,
            // move to the left as elements below are all greater
            else 
                --j;
        }
        
        // If we exit the loop, x was not found
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c, 0));
        int x;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }
        cin >> x;
        Solution ob;
        bool an = ob.matSearch(matrix, x);
        if (an)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends