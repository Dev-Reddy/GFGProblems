//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
        
        vector<int>v(26,0);
        int l = 0;
        
        int ans = 0;
        
        for(int r = 0;r<s.size();r++){
            int ind = s[r] - 'a';
            v[ind]++;
            
            while(l<r && v[ind]>1){
                int indLeftMostChar = s[l] - 'a';
                v[indLeftMostChar]--;
                l++;
            }
            
            ans = max(ans, r-l+1);
        }
        
        return ans;
        
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        Solution obj;
        string s;
        cin >> s;
        cout << obj.longestUniqueSubstr(s) << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends