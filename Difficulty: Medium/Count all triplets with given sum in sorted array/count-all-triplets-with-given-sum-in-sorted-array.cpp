//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countTriplets(vector<int> &arr, int target) {
        // Code Here
        
        int ans = 0;
        
        int n = arr.size();
        
        for(int i = 0;i<n-2;i++){
            int j = i+1, k = n-1;
            while(j<k){
                int sum = arr[i]+arr[j]+arr[k];
                if(sum<target) j++;
                else if(sum>target) k--;
                else {
                   ans++;
                   int next = j+1;
                //   so we are doing this because we want to know
                // how many same elements will pair with the same arr[k]
                // this will happen for all a[x] = a[j];
                    while(next<k && arr[next]==arr[next-1]){
                        ans++;
                        next++;
                    }
                    
                    // as all the possible elements a[j] for the current a[k]
                    // under the current conditions of i, to make the triplet 
                    // have been explored we will decrease k;
                    k--;
                    // we will not increase j because arr[k-1] may be = arr[k]
                }
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

vector<int> lineArray() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> arr;
    int num;
    while (ss >> num) {
        arr.push_back(num);
    }
    return arr;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr = lineArray();
        int target;
        cin >> target;
        cin.ignore();

        Solution ob;
        int res = ob.countTriplets(arr, target);
        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends