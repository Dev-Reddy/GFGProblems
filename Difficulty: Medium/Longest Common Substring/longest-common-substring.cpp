//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestCommonSubstr(string s1, string s2) {
        // your code here
        
        int n = s1.size();
        int m = s2.size();
         vector<int> prev(m+1,0), cur(m+1,0);
        int ans=0;

        //nested loops..
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){ 
                    cur[j]=1+prev[j-1];
                    ans=max(ans,cur[j]);
                }
                
                else{
                    cur[j]=0;
                }
            }
            prev=cur;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;
    }
}
// } Driver Code Ends