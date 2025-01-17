//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        // code here
        int n = arr.size();
        int prod = 1, cntZero = 0;

        // Calculate product of non-zero elements and count zeros
        for (int x : arr) {
            if (x != 0) {
                prod *= x;
            } else {
                ++cntZero;
            }
        }
        
        vector<int> ans(n, 0); // Initialize result array with zeros
        
        // Case 1: If more than one zero, the result is all zeros
        if (cntZero >= 2) return ans;

        // Case 2: If exactly one zero
        if (cntZero == 1) {
            for (int i = 0; i < n; ++i) {
                if (arr[i] == 0) {
                    ans[i] = prod; // Product only at the zero index
                    break;
                }
            }
            return ans;
        }
        
        // Case 3: No zeros in the array
        for (int i = 0; i < n; ++i) {
            ans[i] = prod / arr[i]; // Divide total product by the current element
        }
        
        return ans;
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

        Solution obj;
        vector<int> res = obj.productExceptSelf(arr);

        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends