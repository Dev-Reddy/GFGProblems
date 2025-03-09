//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int countPS(string &s) {
        // code here
         int N=s.size();
        vector<vector<int>>dp(N,vector<int>(N,0));
        for(int i=0;i<N;i++){
            dp[i][i]=1;
        }
        int ct=0;
        for(int L=2;L<=N;L++){
            for(int i=0;i<N-L+1;i++){
                int j=i+L-1;
                if(s[i]==s[j]){
                    if(L==2)dp[i][j]=2;
                    else if(dp[i+1][j-1]>0)dp[i][j]=2+dp[i+1][j-1];
                    else dp[i][j]=0;
                }
                ct+=(dp[i][j]>=2);
            }
        }
        return ct;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.countPS(s) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends