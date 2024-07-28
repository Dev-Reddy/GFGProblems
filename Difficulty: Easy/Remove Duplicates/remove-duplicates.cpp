//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    string removeDups(string str) {
        // Your code goes here
        vector<int>count(26,0);
        string p="";
        
        for(int i=0; i<str.size(); i++)
        {
            if(count[str[i]-'a']==0)
            {
                count[str[i]-'a']++;
                p += str[i];
            }
        }
        return p;
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.removeDups(s) << "\n";
    }

    return 0;
}
// } Driver Code Ends