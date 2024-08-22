//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minimumEnergy(vector<int>& h, int n) {
        // Code here
        int p1 = 0, p2=0;
        
        for(int i =1;i<n;i++){
            int l = p1 + abs(h[i]-h[i-1]);
            int r = INT_MAX;
            if(i>1) r = p2 + abs(h[i]-h[i-2]);
            
            int curr = min(l,r);
            p2 = p1;
            p1 = curr;
        }
        
        return p1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends