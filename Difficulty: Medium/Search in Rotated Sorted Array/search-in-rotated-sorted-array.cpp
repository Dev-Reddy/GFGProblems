//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int search(vector<int>& arr, int key) {
        // complete the function here
        int n = arr.size();
        int start = 0, end = n - 1;
        while (start <= end) {
            int mid = (start + end) / 2;

            // If middle element is the key
            if (arr[mid] == key)
                return mid;

            // If the left part is sorted
            if (arr[start] <= arr[mid]) {
                if (arr[start] <= key && key <= arr[mid]) {
                    // key is in the left part
                    end = mid - 1;
                } else {
                    // key is in the right part
                    start = mid + 1;
                }
            } else { // If the right part is sorted
                if (arr[mid] <= key && key <= arr[end]) {
                    // key is in the right part
                    start = mid + 1;
                } else {
                    // key is in the left part
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends