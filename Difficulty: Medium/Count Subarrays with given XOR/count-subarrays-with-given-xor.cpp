//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // a^b = c
        // a^c = b
        // b^c = a
        // (a^b) ^ (a^b^c) = c 
        
        int n = arr.size();
        map<int,int> mp;
        mp[0] = 1;
        int xr = 0, ans = 0;
        for(int i=0; i<arr.size(); i++)
        {
            xr ^= arr[i];
            
            int rem = xr^k;
            
            if(mp.find(rem) != mp.end()){
                ans += mp[rem];
            }
            mp[xr]++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore(); // Ignore the newline after the number of test cases

    while (tc-- > 0) {
        string input;
        getline(cin, input); // Read the whole line for the array

        stringstream ss(input);
        vector<int> arr;
        int num;

        while (ss >> num) {
            arr.push_back(num); // Push numbers into the vector
        }

        int k;
        cin >> k;
        cin.ignore(); // Ignore the newline after k

        Solution obj;
        cout << obj.subarrayXor(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends