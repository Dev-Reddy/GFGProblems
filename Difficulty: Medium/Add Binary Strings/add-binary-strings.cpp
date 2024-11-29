//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string addBinary(string& s1, string& s2) {
        // your code here
        int tmp = 0;
        int carry = 0;
        string res = "";
        string diffString = "";
    
        string minStr = (s1.length()>s2.length())?s2:s1;
        string maxStr = (minStr == s2)?s1:s2;
        
        int diff = maxStr.length()-minStr.length();
        for(int i=0;i<diff;i++)
        {
            diffString = diffString + '0';
        }
        
        minStr = diffString + minStr;
    
        for(int i=(maxStr.length()-1);i>=0;i--)
        {
            tmp = (maxStr[i]-'0')+(minStr[i]-'0')+carry;
            carry = 0;
            if(tmp == 2)
            {
                carry = 1;
                res = res + '0';
            }
            else if(tmp == 3)
            {
                carry = 1;
                res = res + '1';
            }
            else if(tmp == 1)
            {
                res = res + '1';
                carry = 0;
            }
            else
            {
                res = res + '0';
            }
        }
    
        if(carry == 1)
        {
            res = res + '1';
        }
    
        reverse(res.begin(), res.end());
        
        string newResult = "";
        int index = res.find_first_of('1');
        newResult = res.substr(index, (res.size()-index));
        
        return newResult;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.addBinary(A, B);
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends