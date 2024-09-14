//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maximumPoints(vector<vector<int>>& arr, int n) {
        // Code here
        vector<int>prev(4,0);
        
        for(int i = 0;i<=3;i++){
            for(int j = 0;j<3;j++){
                if(i!=j){
                    prev[i] = max(prev[i], arr[0][j]);
                }
            }
        }
        
        
        
        for(int day = 1;day<n;day++){
            vector<int>curr(4,0);
            for(int last = 0;last<=3;last++){
                for(int task = 0;task<3;task++){
                    if(task!=last){
                        int point = prev[task] + arr[day][task];
                        curr[last] = max(curr[last], point);
                    }
                }   
            }
            prev = curr;
        }
        
        return prev[3];
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
        cout << obj.maximumPoints(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends