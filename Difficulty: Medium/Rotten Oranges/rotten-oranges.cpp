//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<pair<int,int>,int>>q;

        int vis[m][n];

        int cntFresh = 0;

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]==2){
                    vis[i][j]=2;
                    q.push({{i,j},0});
                } else {
                    vis[i][j]=0;
                }

                if(grid[i][j]==1){
                    cntFresh++;
                }
            }
        }

        int time = 0;
        int cnt = 0;
        
        int rdir[] = {-1,0,1,0};
        int cdir[] = {0,1,0,-1};

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;

            time = max(t,time);

            q.pop();

            for(int i = 0;i<4;i++){
                int row = r + rdir[i];
                int col = c + cdir[i];
                if(row>=0 && row<m && col>=0 && col<n && vis[row][col]==0 && grid[row][col]==1){
                    vis[row][col]=2;
                    q.push({{row,col},t+1});
                    cnt++;
                }
            }
        }

        if(cnt!=cntFresh) return -1;

        return time;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(mat);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends