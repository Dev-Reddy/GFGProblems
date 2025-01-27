//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        
        int m = grid.size();
        int n = grid[0].size();
        
        int ans = 0;
        
        // up left, up, up right, left, right, down left, down, down right
        
        int row [] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int col [] = {-1, 0, 1, -1, 1, -1, 0, 1};

        
        
        vector<vector<int>> visited (m, vector<int>(n, 0));
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]=='1' && visited[i][j]==0){
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    visited[i][j] = 1;
                    ans++;
                    while(!q.empty()){
                        auto front = q.front();
                        q.pop();
                        
                        int r = front.first;
                        
                        int c = front.second;
                        
                        for(int k = 0; k < 8; k++){
                            int x = r + row[k];
                            int y = c + col[k];
                            
                            if(x<m && y<n && x>=0 && y>=0){
                                if(grid[x][y]=='1' && visited[x][y]==0){
                                    q.push({x,y});
                                    visited[x][y]=1;
                                }
                            }
                        }
                    }
                }
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends