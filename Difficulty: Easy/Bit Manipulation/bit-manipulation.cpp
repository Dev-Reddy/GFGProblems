//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void bitManipulation(int num, int i) {
        // your code here
        // int a = (num>>i-1) & 1;
        
        // int b = (1<<i-1) | num;
        
        // int c = ~(1<<i) & num;
        
        int a = (num >> (i - 1)) & 1; // Get ith bit
        int b = (1 << (i - 1)) | num; // Set ith bit
        int c = ~(1 << (i - 1)) & num; // Clear ith bit

        cout << a << " " << b << " " << c;
        

        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n >> i;
        Solution ob;
        ob.bitManipulation(n, i);
        cout << "\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends