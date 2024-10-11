//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> rearrange(vector<int>& arr) {
        // Code here
        
        int n=arr.size();
        int start=-1;
        for(int i=0; i<n; i++) {
            if(arr[i]!=-1 && arr[i]!=i) {
                start=arr[i];
                while(arr[start]!=start) {
                    int temp=arr[start];
                    arr[start]=start;
                    if(temp!=-1) start=temp;
                }
            }
        }
        for(int i=0; i<n; i++) if(arr[i]!=i) arr[i]=-1;
        return arr;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        vector<int> arr;
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution solution;
        vector<int> ans = solution.rearrange(arr);

        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends