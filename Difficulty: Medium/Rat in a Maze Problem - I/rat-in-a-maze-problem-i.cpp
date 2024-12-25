//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
    
    
    void helper(vector<vector<int>> &mat, vector<string> &ans, 
    string &path, int r, int c){
        
        if(mat[r][c]!=1) return;
        
        int n = mat.size();
        
        if(r==n-1 && c==n-1){
            ans.push_back(path);
            return;
        }
        
        string dir = "DLRU";
        int rd []= {1,0,0,-1};
        int cd []= {0,-1,1,0};
        
        for(int i = 0;i<4;i++){
            int nextr = r + rd[i];
            int nextc = c + cd[i];
            
            if(nextr>=0 and nextc>=0 && nextr<n && nextc<n && mat[nextr][nextc]==1){
                mat[r][c] = 2;
                path+=dir[i];
                helper(mat, ans, path, nextr, nextc);
                path.pop_back();
                mat[r][c] = 1;
            }
            
        }
    }
    
    
  public:
    vector<string> findPath(vector<vector<int>> &mat) {
        // code here
        vector<string> ans;
        string path = "";
        helper(mat, ans, path, 0, 0);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        vector<vector<int>> mat;
        string innerArray;
        bool isInsideArray = false;

        for (char c : input) {
            if (c == '[') {
                if (isInsideArray) {
                    innerArray.clear();
                }
                isInsideArray = true;
            } else if (c == ']') {
                if (isInsideArray && !innerArray.empty()) {
                    vector<int> row;
                    stringstream ss(innerArray);
                    int num;

                    while (ss >> num) {
                        row.push_back(num);
                        if (ss.peek() == ',')
                            ss.ignore();
                        while (isspace(ss.peek()))
                            ss.ignore();
                    }

                    mat.push_back(row);
                    innerArray.clear();
                }
                isInsideArray = false;
            } else if (isInsideArray) {
                if (!isspace(c)) {
                    innerArray += c;
                }
            }
        }

        Solution obj;
        vector<string> result = obj.findPath(mat);
        sort(result.begin(), result.end());

        if (result.empty())
            cout << "[]";
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends