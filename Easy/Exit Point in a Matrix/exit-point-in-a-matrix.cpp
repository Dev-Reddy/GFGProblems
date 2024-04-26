//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> FindExitPoint(int n, int m, vector<vector<int>>& matrix) {
        
        int i = 0, j = 0, dir = 0;
        while(i >= 0 && j >= 0 && i < n && j < m)
        {
            if(matrix[i][j] == 1)
            {
                dir = (dir+1)%4;
                matrix[i][j] = 0;
            }
            if(dir == 0) j++;
            else if(dir == 1) i++;
            else if(dir == 2) j--;
            else if(dir == 3) i--;
        }
        if(i == -1) i = 0;
        if(j == -1) j = 0;
        if(i == n) i = n-1;
        if(j == m) j = m-1;
        return {i, j};
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        vector<int> ans = obj.FindExitPoint(n, m, matrix);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends