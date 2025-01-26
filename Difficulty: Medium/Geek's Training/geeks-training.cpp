//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    
    int helper(vector<vector<int>>& arr, int index, int lastChoice){
        if(index < 0) return 0;
        
        int ans = 0;
        
        for(int i = 0; i <=2; i++){
            if(i!=lastChoice){
                ans = max(ans, arr[index][i] + helper(arr, index-1, i));
            }
        }
        
        return ans;
    }
    
    
  public:
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
        
        // choice : R - 0, F - 1, L - 2, CHOOSING FIRST TIME 3
        
        int n = arr.size();
        
        
        vector<int>last(4, 0);
        
        for(int i = 0; i < n; i++){
            vector<int>curr(4, 0);
            
            for(int j = 0; j<4; j++){ //traverse last to insert values
                for(int k = 0; k<3; k++){ //traverse day values
                    if(j!=k){
                        curr[j] = max(curr[j], last[k] + arr[i][k]);
                    }
                }
            }
            
            last = curr;
        }
        
        // return helper(arr, n-1, -1);
        
        return last[3];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            arr.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends