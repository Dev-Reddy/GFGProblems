//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
    void helper(vector<vector<int>> &mat, int i, int j, string&temp, vector<string>&ans){
        int n = mat.size();
        if(mat[i][j]!=1) return;
        if(i==n-1 && j==n-1) {
            ans.push_back(temp);
            return;
        }
        if(i>=n || j>=n) return;
        
        if(i!=0 && mat[i-1][j]==1){
            mat[i][j]=2;
            temp+="U";
            helper(mat, i-1, j, temp, ans);
            temp.pop_back();
            mat[i][j]=1;
        }
        if(i!=n-1 && mat[i+1][j]==1){
            mat[i][j]=2;
            temp+="D";
            helper(mat, i+1, j, temp, ans);
            temp.pop_back();
            mat[i][j]=1;
        }
        if(j!=0 && mat[i][j-1]==1){
            mat[i][j]=2;
            temp+="L";
            helper(mat, i, j-1, temp, ans);
            temp.pop_back();
            mat[i][j]=1;
        }
        if(j!=n-1 && mat[i][j+1]==1){
            mat[i][j]=2;
            temp+="R";
            helper(mat, i, j+1, temp, ans);
            temp.pop_back();
            mat[i][j]=1;
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