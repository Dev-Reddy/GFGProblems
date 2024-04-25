//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int findMaxSum(int n, int m, vector<vector<int>> mat) {
        // code here
        int ans=-1;
        for(int i=0;i<(n-2);i++)
        {
            for(int j=1;j<(m-1);j++)
            {
                int tempSum=0;
                //1st row
                tempSum+=(mat[i][j-1]+mat[i][j]+mat[i][j+1]);
                
                //2nd row
                tempSum+=(mat[i+1][j]);
                
                //3rd row
                tempSum+=(mat[i+2][j-1]+mat[i+2][j]+mat[i+2][j+1]);
                
                ans=max(ans,tempSum);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, i, j;
        cin >> N >> M;
        vector<vector<int>> Mat(N, vector<int>(M));
        for (i = 0; i < N; i++)
            for (j = 0; j < M; j++) cin >> Mat[i][j];
        Solution ob;
        cout << ob.findMaxSum(N, M, Mat) << "\n";
    }
}
// } Driver Code Ends