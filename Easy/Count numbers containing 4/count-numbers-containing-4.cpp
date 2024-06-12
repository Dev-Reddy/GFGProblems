//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countNumberswith4(int n) {
        int count = 0;
        for (int i = 1; i <= n; ++i) {
            if (containsDigitFour(i)) {
                count++;
            }
        }
        return count;
    }

  private:
    bool containsDigitFour(int number) {
        string numStr = to_string(number);
        return numStr.find('4') != string::npos;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        int res = obj.countNumberswith4(n);

        cout << res << endl;
    }
}

// } Driver Code Ends