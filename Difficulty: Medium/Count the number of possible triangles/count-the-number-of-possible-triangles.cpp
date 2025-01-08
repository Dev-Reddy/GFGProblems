//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to count the number of possible triangles.
    int countTriangles(vector<int>& arr) {
        // code here
        int ans=0;
        int n = arr.size();
        sort(arr.begin(),arr.end(),greater<int> ());
        for(int i=0;i<n-2;i++){
            int largerSide = arr[i];
            int l=i+1,r=n-1;
            while(l<r){
                if(arr[l]+arr[r]>largerSide){
                    ans+=r-l;
                    l++;
                }
                else
                    r--;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.countTriangles(a) << "\n~\n";
    }

    return 0;
}

// } Driver Code Ends