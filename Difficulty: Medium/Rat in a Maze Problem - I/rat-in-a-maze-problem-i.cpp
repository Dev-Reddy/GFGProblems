//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
    int di[4] = {1,0,0,-1};
    int dj[4] = {0,-1,1,0};
    
    void helper(vector<vector<int>> &mat, int i, int j, string&temp, vector<string>&ans){
        int n = mat.size();
        if(mat[i][j]!=1) return;
        
        if(i==n-1 && j==n-1) {
            ans.push_back(temp);
            return;
        }
        string dir="DLRU";
        for(int k = 0;k<4;k++){
            int nexti = i+di[k];
            int nextj = j+dj[k];
            if(nexti>=0 && nextj>=0 && nexti<n && nextj<n && mat[nexti][nextj]==1){
                mat[i][j]=2;
                temp+=dir[k];
                helper(mat, nexti, nextj, temp, ans);
                mat[i][j]=1;
                temp.pop_back();
            }
        }
    }
    
  public:
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        string temp = "";
        vector<string> ans;
        int i = 0, j=0;
        helper(mat, i, j, temp, ans);
        return ans;
    
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends