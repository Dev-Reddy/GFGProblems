//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    public:
    int f(int day  , int lasttask , vector<vector<int>>&arr , vector<vector<int>>&dp)
  {
      if(dp[day][lasttask]!=-1)
      return dp[day][lasttask];
      if(day==0)
      {
          int maxi=0;
          for(int task=0;task<3;task++)
          {
              if(task!=lasttask)
              {
              maxi=max(arr[day][task], maxi);
              }
          }
          return dp[day][lasttask]=maxi;
      }
      int maxi=0;
      for(int task = 0 ; task < 3 ; task++)
      {
          if(task!=lasttask){
          int points = arr[day][task]+ f(day-1, task , arr , dp);
          maxi= max(points, maxi);
      }
      }
      return dp[day][lasttask]=maxi ;
     
  }
    int maximumPoints(vector<vector<int>>& arr, int n) {
        // Code here
        vector<vector<int>>dp(n, vector<int>(4,-1));
        return f(n-1,3 , arr , dp);
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