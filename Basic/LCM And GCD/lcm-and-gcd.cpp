//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<long long> lcmAndGcd(long long A , long long B) {
        // code here
        
        long long a = A, b = B;
        
        while(a>0 && b>0){
            if(a>=b){
                a%=b;
            } else {
                b%=a;
            }
        }
        
        if(a==0){
            return {(A*B)/b, b};
        } else {
            return {(A*B)/a, a};
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long A,B;
        
        cin>>A>>B;

        Solution ob;
        vector<long long> ans = ob.lcmAndGcd(A,B);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}
// } Driver Code Ends