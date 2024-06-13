//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int padovanSequence(int n) {
        // code here.
        if(n<=2)return 1;
        int mod=1e9+7;
       int a0=1,a1=1,a2=1,ans=0;
       for(int i=3;i<=n;i++){
            ans=(a0+a1)%mod;
            a0=a1,a1=a2,a2=ans;
       }
       return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.padovanSequence(n) << endl;
    }
    return 0;
}
// } Driver Code Ends