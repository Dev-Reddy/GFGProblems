//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        // code here
        int n=arr.size();
        if(n==1)return;
        for(int i=n-2;i>=0;i--){
            if(arr[i]<arr[i+1]){
                int ele = arr[i];
                int idx=i;
                int k = INT_MAX;
                for(int j=i+1;j<n;j++){
                    if(arr[j]<k and arr[j]>arr[i]){
                        k=arr[j];
                        idx = j;
                    }
                }
                swap(arr[i],arr[idx]);
                sort(arr.begin()+i+1, arr.end());
                
                return;
            }
        }
        sort(arr.begin(), arr.end());
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int n = arr.size();
        ob.nextPermutation(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends