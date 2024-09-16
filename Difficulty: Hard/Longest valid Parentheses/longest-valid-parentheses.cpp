//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxLength(string& str) {
        // code here
        
        int ans=0,o=0,c=0;
        for(int i=0;i<str.length();i++)
        {
            if(str[i]=='(') o++;
            else c++;
            if(c>o) o=c=0;
            if(c==o) ans=max(ans,c*2);
        }
        o=c=0;
        for(int i=str.length()-1;i>=0;i--)
        {
            if(str[i]=='(')o++;
            else c++;
            if(c<o) o=c=0;
            if(c==o) ans=max(ans,c*2);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.maxLength(S) << "\n";
    }
    return 0;
}
// } Driver Code Ends