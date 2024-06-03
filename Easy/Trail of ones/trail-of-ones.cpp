//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int numberOfConsecutiveOnes(int n) {
        // code here
        
        int mod=1e9+7;
         vector<int> pre(3,0);
        pre[2]=1;
        
        for(int i=1;i<=n;i++)
        {
            vector<int> curr(3,0);
            for(int j=0;j<=2;j++)
            {
                int a=0;
                int b=0;
                
                if(j==2)
                a=pre[j];
                else
                a=pre[0];
                
                if(j==0)
                b=pre[1];
                else
                b=pre[2];
                
                curr[j]=(a+b)%mod;
            }
            pre=curr;
        }
        
        return pre[0];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.numberOfConsecutiveOnes(N) << endl;
    }
    return 0;
}

// } Driver Code Ends