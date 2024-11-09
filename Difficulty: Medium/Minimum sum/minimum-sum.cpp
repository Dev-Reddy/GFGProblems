//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    string minSum(vector<int> &arr) {
        // code here
        int n = arr.size();
        string ans;
        int carry = 0;
        sort(arr.begin(), arr.end());
        for (int i = n - 1; i >= 0; i--) {
            int cur = arr[i] + carry;
            if (i)i--, cur += arr[i];
            carry = cur / 10, cur %= 10;
            ans.push_back(char(cur + '0'));
        }
        if (carry)ans.push_back(char(carry + '0'));
        while (ans.back() == '0')ans.pop_back();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        string ans = ob.minSum(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends