//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:

    string longestCommonPrefix(vector<string> s) {
        // your code here
        sort(s.begin(),s.end());
        string ans = "";

        string f = s[0], l = s[s.size()-1];

        for(int i = 0;i<min(f.size(), l.size());i++){
            if(f[i]!=l[i]){
                return ans==""?"-1":ans;
            }
            ans+=f[i];
        }

        return ans==""?"-1":ans; 
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}

// } Driver Code Ends