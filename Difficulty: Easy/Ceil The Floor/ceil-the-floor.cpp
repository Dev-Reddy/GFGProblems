//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User code template

class Solution {
    
    int findFloor(vector<int>& arr, int k) {

        // Your code here
        
        int low = 0, high = arr.size()-1;
        
        int ans = -1;
        
        while(low<=high){
            int mid = (low+high)/2;
            
            if(arr[mid]<=k){
                ans = mid;
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        
        return ans;
    }
    
    
    int findCeil(vector<int>& arr, int k) {

        // Your code here
        
        int low = 0, high = arr.size()-1;
        
        int ans = arr.size();
        
        while(low<=high){
            int mid = (low+high)/2;
            
            if(arr[mid]>=k){
                ans = mid;
                high = mid-1;
                
            } else {
                low = mid+1;
            }
        }
        
        return ans;
    }
    
    
  public:
    vector<int> getFloorAndCeil(int x, vector<int> &arr) {
        // code here
        
        sort(arr.begin(), arr.end());
        
        int f = findFloor(arr, x);
        int c = findCeil(arr, x);
        
        vector<int>ans;
        
        if(f==-1) ans.push_back(-1);
        else ans.push_back(arr[f]);
        
        if(c==arr.size()) ans.push_back(-1);
        else ans.push_back(arr[c]);
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t
    while (t--) {
        vector<int> arr;
        int x;
        string input;
        cin >> x;
        cin.ignore();

        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        auto ans = ob.getFloorAndCeil(x, arr);
        cout << ans[0] << " " << ans[1] << "\n~\n";
    }
    return 0;
}
// } Driver Code Ends